#include<bits/stdc++.h>
#define N 200010
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int n,len,num;
vector<int> g[1010];
void qk(int x)
{
	for(int i=num+1;i>=x+2;i--)
		g[i].assign(g[i-1].begin(),g[i-1].end());
	g[x+1].assign(g[x].begin()+len,g[x].end());
	while(g[x].size()>len)
		g[x].pop_back();
	num++;
}
pii find(int x)
{
	int p=0;
	while(x>g[p].size())
		x-=g[p++].size();
	return mp(p,x);
}
int main()
{
	while(~scanf("%d",&n))
	{
		len=sqrt(n);
		for(int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			pii pos=find(x);
			g[pos.first].insert(g[pos.first].begin()+pos.second,y);
			if(g[pos.first].size()>3*len)
				qk(pos.first);
		}
		for(int i=0;i<=num;i++)
		{
			for(int j=0;j<g[i].size();j++)
				printf("%d ",g[i][j]);
			g[i].clear();
		}
		printf("\n");
	}
	return 0;
}
