#include <bits/stdc++.h>
#define rep(i, l, r) for(register int i = (l); i <= (r); ++i)
using namespace std;
int dp[8388618];
int main()
{
	register int n, m = 1, t = 0, b, c, d;
	register long long ans = 0;
	scanf("%d%d%d%d%d", &n, &dp[0], &b, &c, &d);
	while(n > m)
		m <<= 1, t++;
	rep(i, 0, n-2)
		dp[i+1] = (1ll*dp[i]*(dp[i]+b)+c)%d;
	rep(j, 0, t)
		rep(i, 0, m)
			if((i>>j)&1)
				dp[i] ^= dp[i^(1<<j)];
	rep(i, 0, n-1)
		ans ^= dp[i]*(i+1ll);
	printf("%lld", ans);
	return 0;
}