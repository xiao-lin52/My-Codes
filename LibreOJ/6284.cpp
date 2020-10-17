#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,len,num,a[N],belong[N],tag[N],v[N],p[N],l[N],r[N];
vector<int> g[N];
void resort(int x)
{
	g[x].clear();
	for(int i=l[x];i<=r[x];i++)
		g[x].push_back(a[i]);
	sort(g[x].begin(),g[x].end());
}
void push_down(int x)
{
	if(!v[x])
		return;
	g[x].assign(r[x]-l[x]+1,tag[x]);
	for(int i=l[x];i<=r[x];i++)
		a[i]=tag[x];
	v[x]=0;
}
int judge(int x,int y,int k)
{
	int sum=0;
	if(v[belong[x]])
		if(tag[belong[x]]==k)
			return y-x+1;
		else
			return 0;
	if(p[belong[x]])
		if(a[x]==k)
			return y-x+1;
		else
			return 0;
		for(int i=x;i<=y;i++)
			if(a[i]==k)
				sum++;
	return sum;
}
void check(int x)
{
	for(int i=1;i<g[x].size();i++)
		if(g[x][i]!=g[x][i-1])
		{
			p[x]=0;
			return;
		}
	p[x]=1;
}
void update(int x,int y,int k)
{
	if(belong[x]==belong[y])
	{
		push_down(belong[x]);
		for(int i=x;i<=y;i++)
			a[i]=k;
		resort(belong[x]);
		check(belong[x]);
		return;
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
	{
		tag[i]=k;
		v[i]=1;
	}
	push_down(belong[x]);
	push_down(belong[y]);
	for(int i=x;i<=r[belong[x]];i++)
		a[i]=k;
	for(int i=l[belong[y]];i<=y;i++)
		a[i]=k;
	resort(belong[x]);
	resort(belong[y]);
	check(belong[x]);
	check(belong[y]);
}
int query(int x,int y,int k)
{
	int sum=0;
	if(belong[x]==belong[y])
		return judge(x,y,k);
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
	{
		if(v[i])
		{
			if(tag[i]==k)
				sum+=r[i]-l[i]+1;
			continue;
		}
		if(p[i])
		{
			if(a[l[i]]==k)
				sum+=r[i]-l[i]+1;
			continue;
		}
		sum+=upper_bound(g[i].begin(),g[i].end(),k)-lower_bound(g[i].begin(),g[i].end(),k);
	}
	return sum+judge(x,r[belong[x]],k)+judge(l[belong[y]],y,k);
}
int main()
{
	scanf("%d",&n);
	len=sqrt(n);
	num=(n-1)/len+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		belong[i]=(i-1)/len+1;
		g[belong[i]].push_back(a[i]);
	}
	for(int i=1;i<=num;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=min(i*len,n);
		sort(g[i].begin(),g[i].end());
		check(i);
	}
	for(int i=1;i<=n;i++)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		printf("%d\n",query(l,r,c));
		update(l,r,c);
	}
	return 0;
}
