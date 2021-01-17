#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
namespace IO
{
	char buf[1<<23], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
	#define isdigit(c) (c >= 48 && c <= 57)
	#define isalpha(c) ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	template<typename T> inline void read(T &x)
	{
		x = 0;
		register char ch = getchar();
		while(!isdigit(ch))
			ch = getchar();
		while(isdigit(ch))
		{
			x = (x<<1)+(x<<3)+(ch^48);
			ch = getchar();
		}
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
typedef long long ll;
const int N = 1e5+10, inf = 0x3f3f3f3f;
struct ALTXDY
{
	int val;
	int type;
	bool operator < (const ALTXDY &b) const
	{
		return val == b.val ? type < b.type : val < b.val;
	}
};
ALTXDY qwq[N<<1];
int n, m, a, b, k, c[N];
stack<int> st;
queue<ALTXDY> q;
int main()
{
	read(n, m);
	rep(i, 1, n)
	{
		read(a);
		qwq[i] = (ALTXDY){a, 1};
	}
	rep(i, 1, n)
	{
		read(b);
		qwq[i+n] = (ALTXDY){m-1-b, 2};
	}
	sort(qwq+1, qwq+1+2*n);
	rep(i, 1, 2*n)
		q.push(qwq[i]);
	while(q.size())
	{
		if(q.front().type == 1)
			st.push(q.front().val);
		else
			if(st.size())
				c[++k] = (m-1+st.top()-q.front().val)%m, st.pop();
			else
				q.push(q.front());
		q.pop();
	}
	sort(c+1, c+1+n);
	per(i, n, 1)
		printf("%d ", c[i]);
	return 0;
}