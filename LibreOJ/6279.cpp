#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,len,a[N],belong[N],l[N],r[N],tag[N];
vector<int> g[N];
void resort(int x)
{
	g[x].clear();
	for(int i=l[x];i<=r[x];i++)
		g[x].push_back(a[i]);
	sort(g[x].begin(),g[x].end());
}
void update(int x,int y,int k)
{
	if(belong[x]==belong[y])
	{
		for(int i=x;i<=y;i++)
			a[i]+=k;
		resort(belong[x]);
		return;
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
		tag[i]+=k;
	for(int i=x;i<=r[belong[x]];i++)
		a[i]+=k;
	for(int i=l[belong[y]];i<=y;i++)
		a[i]+=k;
	resort(belong[x]);
	resort(belong[y]);
}
int query(int x,int y,int k)
{
	int ans=-1;
	if(belong[x]==belong[y])
	{
		for(int i=x;i<=y;i++)
			if(a[i]+tag[belong[i]]<k)
				ans=max(ans,a[i]+tag[belong[i]]);
		return ans;
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
		if(g[i][0]+tag[i]<k)
			ans=max(ans,g[i][lower_bound(g[i].begin(),g[i].end(),k-tag[i])-g[i].begin()-1]+tag[i]);
	for(int i=x;i<=r[belong[x]];i++)
		if(a[i]+tag[belong[i]]<k)
			ans=max(ans,a[i]+tag[belong[i]]);
	for(int i=l[belong[y]];i<=y;i++)
		if(a[i]+tag[belong[i]]<k)
			ans=max(ans,a[i]+tag[belong[i]]);
	return ans;
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
	{
		for(int j=l[i];j<=r[i];j++)
		{
			belong[j]=i;
			g[i].push_back(a[j]);
		}
		sort(g[i].begin(),g[i].end());
	}
	for(int i=1;i<=n;i++)
	{
		int op,l,r,c;
		scanf("%d%d%d%d",&op,&l,&r,&c);
		if(op)
			printf("%d\n",query(l,r,c));
		else
			update(l,r,c);
	}
	return 0;
}
