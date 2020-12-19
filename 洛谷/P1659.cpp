#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10, mod = 19930726;
ll ksm(ll b, ll k)
{
	ll ans = 1;
	while (k)
	{
		if(k&1)
			ans = ans*b%mod;
		k >>= 1;
		b = b*b%mod;
	}
	return ans;
}
ll n, k, x, y, cnt, ans = 1, flag, d[N * 2], b[N * 2], sum[N * 2], pre[N*2];
char str[N * 2];
int main()
{
	scanf("%lld%lld%s", &n, &k, str+1);
	for (int i = 1; i <= n; i++)
	{
		int k = i > y ? 1 : min(d[x + y - i], y - i);
		while (i-k > 0 && i+k <= n && str[i - k] == str[i + k])
			k++;
		d[i] = --k;
		if(i + k > y)
		{
			x = i - k;
			y = i + k;
		}
		sum[d[i]*2+1]++;
	}
	for (int i = (n%2 == 0 ? n-1 : n); i >= 1; i -= 2)
	{
		if(k >= sum[i])
		{
			ans = ans*ksm(i, sum[i])%mod;
			k -= sum[i];
			if(i == 1)
				break;
			else
				sum[i-2] += sum[i];
		}
		else
		{
			flag=1;
			ans = ans*ksm(i, k)%mod;
			break;
		}
	}
	if(flag)
		printf("%lld", ans);
	else
		printf("-1");
	return 0;
}