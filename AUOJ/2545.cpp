#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int N=1e6+10;
int n,m,l=1,r,mid,sum,w[N];
vector<pii> edge[N];
int check(int u,int fa)
{
	sum+=w[u];
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i].first,c=edge[u][i].second;
		if(v!=fa&&c<=mid)
		{
			if(check(v,u))
				return 1;
		}
	}
	if(sum>=m)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		edge[u].push_back(mp(v,c));
		edge[v].push_back(mp(u,c));
		r=max(r,c);
	}
	while(l<r)
	{
		sum=0;
		mid=(l+r)>>1;
		if(check(1,0))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d",l);
	return 0;
}