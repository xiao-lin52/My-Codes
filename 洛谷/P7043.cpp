#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace IO
{
	template <typename T> inline void read(T &r)
	{
		r=0;
		const int M=1e6;
		static streambuf* in=cin.rdbuf();
		#define gc (p1==p2&&(p2=(p1=buf)+in->sgetn(buf, M),p1==p2)?-1:*p1++)
		static char buf[M],*p1,*p2;
		register int c=gc,f=1;
		while(c<48) f=c==45?-1:1,c=gc;
		while(c>47) r=(r<<3)+(r<<1)+(c&15),c=gc;
		r*=f;
	}
	template <typename T> inline void write(T x)
	{
		static streambuf* out = cout.rdbuf();
		#define pc out -> sputc
		if(x<0) pc(45),x=-x;
		if(!x)
			pc(48);
		else
		{
			static char c[30];
			register int sz = 0;
			while(x) c[++sz]=x%10+48,x/=10;
			while(sz) pc(c[sz--]);
		}
		pc(10);
	}
}
using namespace IO;
const ll N=2e6+10;
ll t,n,m,a[N];
vector<ll> edge[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read(t);
	while(t--)
	{
		read(n);
		read(m);
		for(int i=1;i<=n;i++)
			edge[i].clear();
		ll mx=0,u=n+1;
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
			if(mx<a[i])
			{
				mx=a[i];
				u=i;
			}
		}
		for(int i=1;i<=n-1;i++)
		{
			ll u,v;
			read(u);
			read(v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(n==1)
		{
			write(1);
			continue;
		}
		ll v=n+1;
		mx=0;
		sort(edge[u].begin(),edge[u].end());
		for(int i=0;i<edge[u].size();i++)
			if(mx<a[edge[u][i]])
			{
				mx=a[edge[u][i]];
				v=edge[u][i];
			}
		m=m-(a[u]-a[v]);
		if(m<0)
			write(u);
		else
			if(v<u)
				if(m%2==1)
					write(u);
				else
					write(v);
			else
				if(m%2==1)
					write(v);
				else
					write(u);
	}
	return 0;
}