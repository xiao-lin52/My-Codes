#include<bits/stdc++.h>
#define pii pair<int,ll>
#define mp make_pair
using namespace std;
namespace IO
{
	char buf[1<<23],*p1=buf,*p2=buf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	#define isdigit(c) (c>=48&&c<=57)
	#define isalpha(c) (c>=65&&c<=90)
	template<typename T> inline void read(T &x)
	{
		x=0;
		register char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
typedef long long ll;
const int N=3e5+10;
int n,m,flag,vis[N];
ll l,r,cnt[N];
vector<pii> edge[N];
int check(int u,ll step,ll k)
{
	memset(vis,0,sizeof(vis));
	queue<pii> q;
	q.push(mp(1,1));
	while(q.size())
	{
		int u=q.front().first;
		ll num=q.front().second;
		if(u==n)
			return 1;
		q.pop();
		vis[u]=1;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first;
			ll c=edge[u][i].second;
			if(num*c<=k&&!vis[v])
				q.push(mp(v,num+1));
		}
	}
	return 0;
}
int main()
{
	read(n,m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll c;
		read(u,v,c);
		edge[u].push_back(mp(v,c));
		r=max(r,c);
	}
	l=1;
	r*=m;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(1,1,mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%lld",l);
	return 0;
}