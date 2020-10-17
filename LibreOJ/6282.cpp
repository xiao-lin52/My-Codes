#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,a,len,num;
vector<int> g[100010];
vector<int> t;
pii findpos(int x)
{
	int cnt=1;
	while(x>g[cnt].size())
	{
		x-=g[cnt].size();
		cnt++;
	}
	return mp(cnt,x-1);
}
void rebuild(int x)
{
	t.clear();
	for(int i=1;i<=num;i++)
	{
		for(int j=0;j<g[i].size();j++)
			t.push_back(g[i][j]);
		g[i].clear();
	}
	len=sqrt(t.size());
	num=(t.size()-1)/len+1;
	for(int i=0;i<t.size();i++)
		g[i/len+1].push_back(t[i]);
}
void update(int x,int k)
{
	pii pos=findpos(x);
	g[pos.first].insert(g[pos.first].begin()+pos.second,k);
	if(g[pos.first].size()>3*len)
	{
		rebuild(pos.first);
	}
}
int query(int x)
{
	pii pos=findpos(x);
	return g[pos.first][pos.second];
}
int main()
{
	scanf("%d",&n);
	len=sqrt(n);
	num=(n-1)/len+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		g[(i-1)/len+1].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		int op,l,r,c;
		scanf("%d%d%d%d",&op,&l,&r,&c);
		if(op)
			printf("%d\n",query(r));
		else
			update(l,r);
	}
	return 0;
}
