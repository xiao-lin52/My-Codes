#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define rep(i, l, r) for(ll i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(ll i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
namespace IO
{
	char buf[1<<23],*p1=buf,*p2=buf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	#define isdigit(c) (c>=48&&c<=57)
	#define isalpha(c) ((c>=65&&c<=90)||(c>=97&&c<=122))
	template<typename T> inline void read(T &x)
	{
		x=0;
		register int f=1;
		register char ch=getchar();
		while(!isdigit(ch))
		{
			if(ch==45)
				f=-1;
			ch=getchar();
		}
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
		x*=f;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
typedef long long ll;
const ll N = 5e4+10, inf = 0x3f3f3f3f;
struct Task
{
	ll t, s, p, id;
	bool operator < (const Task &x) const
	{
		return p < x.p;
	}
};
bool cmp(Task x, Task y)
{
	return x.t == y.t ? x.p > y.p : x.t < y.t;
}
Task a[N];
ll n, e, fk, ab, l = 1, r, x, ans[N];
map<ll, ll> b;
vector<ll> aaa;
priority_queue<Task> q;
void check()
{
	ll now = 0, flag = 0;
	rep(i, 1, n)
	{
		q.push(a[i]);
		if(i == fk)
			flag = 1;
		now = a[i].t;
		if(i < n)
		{
			Task tmp = q.top();
			q.pop();
			while(tmp.s <= a[i+1].t-now)
			{
				ans[tmp.id] = now+tmp.s;
				if(tmp.id == ab)
					flag = 0;
				if(flag && tmp.id != ab)
					x = min(x, tmp.p);
				now += tmp.s;
				if(q.size())
				{
					tmp = q.top();
					q.pop();
				}
				else
					goto l;
			}
			tmp.s -= a[i+1].t-now;
			q.push(tmp);
			l:;
		}
	}
	while(q.size())
	{
		Task tmp = q.top();
		q.pop();
		ans[tmp.id] = now+tmp.s;
		now += tmp.s;
	}
}
signed main()
{
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	read(n);
	rep(i, 1, n)
	{
		read(a[i].t, a[i].s, a[i].p);
		a[i].id = i;
		x = r = max(r, a[i].p+1);
		if(~a[i].p)
		{
			b[a[i].p] = 1;
			aaa.push_back(a[i].p);
		}
		else
			ab = i;
	}
	sort(a+1, a+1+n, cmp);
	read(e);
	rep(i, 1, n)
		if(a[i].p == -1)
		{
			fk = i;
			break;
		}
	while(l <= r)
	{
		a[fk].p = (l+r)>>1;
		check();
		if(ans[a[fk].id] == e)
			break;
		else if(ans[a[fk].id] < e)
			r = a[fk].p-1;
		else
			l = a[fk].p+1;
	}
	if(b[a[fk].p])
	{
		sort(aaa.begin(), aaa.end());
		ll tmp = lower_bound(aaa.begin(), aaa.end(), x)-aaa.begin();
		if(tmp == 0)
			a[fk].p = x-1;
		else if(tmp == n-1)
			a[fk].p = x;
		else
		{
			while(aaa[tmp] == aaa[tmp-1]+1)
				tmp--;
			a[fk].p = aaa[tmp]-1;
		}
	}
	printf("%lld\n", a[fk].p);
	rep(i, 1, n)
		printf("%lld ", ans[i]);
	return 0;
}