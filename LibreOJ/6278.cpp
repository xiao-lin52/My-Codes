#include<bits/stdc++.h>
#define N 50010
using namespace std;
int n,len,a[N],belong[N],L[N],R[N],tag[N];
vector<int> b[N];
void resort(int x)
{
	b[x].clear();
	for(int i=L[x];i<=R[x];i++)
		b[x].push_back(a[i]);
	sort(b[x].begin(),b[x].end());
}
void update(int l,int r,long long k)
{
	if(belong[l]==belong[r])
	{
		for(int i=l;i<=r;i++)
			a[i]+=k;
		resort(belong[l]);
	}
	else
	{
		for(int i=belong[l]+1;i<=belong[r]-1;i++)
			tag[i]+=k;
		for(int i=l;i<=R[belong[l]];i++)
			a[i]+=k;
		for(int i=L[belong[r]];i<=r;i++)
			a[i]+=k;
		resort(belong[l]);
		resort(belong[r]);
	}
}
int query(int l,int r,long long k)
{
	int sum=0;
	if(belong[l]==belong[r])
	{
		for(int i=l;i<=r;i++)
			if(a[i]+tag[belong[i]]<k)
				sum++;
	}
	else
	{
		for(int i=belong[l]+1;i<=belong[r]-1;i++)
			sum+=lower_bound(b[i].begin(),b[i].end(),k-tag[i])-b[i].begin();
		for(int i=l;i<=R[belong[l]];i++)
			if(a[i]+tag[belong[i]]<k)
				sum++;
		for(int i=L[belong[r]];i<=r;i++)
			if(a[i]+tag[belong[i]]<k)
				sum++;
	}
	return sum;
}
int main()
{
	scanf("%d",&n);
	len=sqrt(n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=len;i++)
	{
		L[i]=R[i-1]+1;
		R[i]=i*len;
	}
	if(R[len]<n)
	{
		len++;
		L[len]=R[len-1]+1;
		R[len]=n;
	}
	for(int i=1;i<=len;i++)
	{
		for(int j=L[i];j<=R[i];j++)
		{
			b[i].push_back(a[j]);
			belong[j]=i;
		}
		sort(b[i].begin(),b[i].end());
	}
	for(int i=1;i<=n;i++)
	{
		int op,l,r;
		long long c;
		scanf("%d%d%d%lld",&op,&l,&r,&c);
		if(!op)
			update(l,r,c);
		else
			printf("%d\n",query(l,r,c*c));
	}
	return 0;
}
