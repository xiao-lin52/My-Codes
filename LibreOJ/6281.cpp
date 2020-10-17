#include<bits/stdc++.h>
#define N 50010
using namespace std;
int n,len,a[N],belong[N],l[N],r[N],p[N],sum[N];
void process(int i)
{
	int t=sqrt(a[i]);
	if(a[i]!=1&&a[i]!=0&&(t==1||t==0))
		p[belong[i]]--;
	sum[belong[i]]+=t-a[i];
	a[i]=t;
}
void update(int x,int y)
{
	if(belong[x]==belong[y])
	{
		for(int i=x;i<=y;i++)
			process(i);
		return;
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
		if(p[i])
			for(int j=l[i];j<=r[i];j++)
				process(j);
	for(int i=x;i<=r[belong[x]];i++)
		if(p[belong[i]])
			process(i);
	for(int i=l[belong[y]];i<=y;i++)
		if(p[belong[i]])
			process(i);
}
int query(int x,int y)
{
	int s=0;
	if(belong[x]==belong[y])
	{
		for(int i=x;i<=y;i++)
			s+=a[i];
		return s;
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
		s+=sum[i];
	for(int i=x;i<=r[belong[x]];i++)
		s+=a[i];
	for(int i=l[belong[y]];i<=y;i++)
		s+=a[i];
	return s;
}
int main()
{
	scanf("%d",&n);
	len=sqrt(n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=len;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=i*len;
	}
	if(r[len]<n)
	{
		len++;
		l[len]=r[len-1]+1;
		r[len]=n;
	}
	for(int i=1;i<=len;i++)
		for(int j=l[i];j<=r[i];j++)
		{
			belong[j]=i;
			sum[i]+=a[j];
			if(a[j]!=1&&a[j]!=0)
				p[i]++;
		}
	for(int i=1;i<=n;i++)
	{
		int op,l,r;
		scanf("%d%d%d%*d",&op,&l,&r);
		if(op)
			printf("%d\n",query(l,r));
		else
			update(l,r);
	}
	return 0;
}
