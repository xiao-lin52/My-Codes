#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
using namespace std;
typedef long long ll;
const int N = 1e5+10, inf = 0x3f3f3f3f;
int n, ans, v[N], c[N], l[N], r[N], dp[N], last[N];
stack<int> st;
void qwq(int x)
{
	if(!x)
		return;
	st.push(x);
	qwq(last[x]);
}
int main()
{
	map<pii, int> b;
	scanf("%d", &n);
	rep(i, 1, n)
	{
		scanf("%d%d%d%d", &v[i], &c[i], &l[i], &r[i]);
		if(!l[i])
			dp[i] = v[i];
		if(dp[b[mp(l[i], r[i]+c[i])]] > dp[i])
		{
			last[i] = b[mp(l[i], r[i]+c[i])];
			dp[i] = dp[last[i]]+v[i];
		}
		if(!r[i] && dp[ans] < dp[i])
			ans = i;
		b[mp(l[i]+c[i], r[i])] = dp[b[mp(l[i]+c[i], r[i])]] > dp[i] ? b[mp(l[i]+c[i], r[i])] : i;
	}
	qwq(ans);
	printf("%d\n", st.size());
	while(st.size())
	{
		printf("%d ", st.top());
		st.pop();
	}
	return 0;
}