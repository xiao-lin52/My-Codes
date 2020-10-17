#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
using namespace std;
const int SIZE=500000;
struct HashTable
{
	vector<pii> hash[SIZE];
	void add(ll x)
	{
		for(int i=0;i<hash[x%SIZE].size();i++)
			if(hash[x%SIZE][i].first==x)
			{
				hash[x%SIZE][i].second++;
				return;
			}
		hash[x%SIZE].push_back(mp(x,1));
	}
	int find(ll x)
	{
		for(int i=0;i<hash[x%SIZE].size();i++)
			if(hash[x%SIZE][i].first==x)
				return hash[x%SIZE][i].second;
		return 0;
	}
	void clear()
	{
		for(int i=0;i<SIZE;i++)
			hash[i].clear();
	}
};
HashTable p[30];
ll ans,w,edge[30][30][2];
int t,n;
inline void dfs1(int x,int y,ll num)
{
	if(x+y==n+1)
	{
		ans+=p[x].find(num);
		return;
	}
	if(x+1<=n)
		dfs1(x+1,y,num^edge[x][y][1]);
	if(y+1<=n)
		dfs1(x,y+1,num^edge[x][y][0]);
}
inline void dfs2(int x,int y,ll num)
{
	if(x+y==n+1)
	{
		p[x].add(num);
		return;
	}
	if(x-1>=1)
		dfs2(x-1,y,num^edge[x-1][y][1]);
	if(y-1>=1)
		dfs2(x,y-1,num^edge[x][y-1][0]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d",&n,&w);
		for(int i=1;i<=n;i++)
			p[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n-1;j++)
				scanf("%lld",&edge[i][j][0]);
		for(int i=1;i<=n-1;i++)
			for(int j=1;j<=n;j++)
				scanf("%lld",&edge[i][j][1]);
		dfs2(n,n,w);
		dfs1(1,1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
