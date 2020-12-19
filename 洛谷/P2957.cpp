#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10, mod1 = 19260817, mod2 = 1000000007, base1 = 131, base2 = 101;
char len1, len2, a[N], b[N];
pii h1[N], h2[N];
ll ans, b1[N], b2[N];
void hash1()
{
	for (int i = 1; i <= len1; i++)
		h1[i] = mp((h1[i - 1].first * base1 % mod1 + (a[i] - 'a')) % mod1, (h1[i - 1].second * base2 % mod2 + (a[i] - 'a')) % mod2);
	for (int i = 1; i <= len2; i++)
		h2[i] = mp((h2[i - 1].first * base1 % mod1 + (b[i] - 'a')) % mod1, (h2[i - 1].second * base2 % mod2 + (b[i] - 'a')) % mod2);
	for (int i = 1; i <= max(len1, len2); i++)
	{
		b1[i] = b1[i - 1] * base1 % mod1;
		b2[i] = b2[i - 1] * base2 % mod2;
	}
}
int cmp(ll x1, ll y1, ll x2, ll y2)
{
	pii tmp1 = mp(((h1[y1].first - h1[x1 - 1].first * b1[y1 - x1 + 1] % mod1) % mod1 + mod1) % mod1, ((h1[y1].second - h1[x1 - 1].second * b2[y1 - x1 + 1] % mod2) % mod2 + mod2) % mod2);
	pii tmp2 = mp(((h2[y2].first - h2[x2 - 1].first * b1[y2 - x2 + 1] % mod1) % mod1 + mod1) % mod1, ((h2[y2].second - h2[x2 - 1].second * b2[y2 - x2 + 1] % mod2) % mod2 + mod2) % mod2);
	return tmp1 == tmp2;
}
int main()
{
	scanf("%s%s", a + 1, b + 1);
	len1 = strlen(a + 1);
	len2 = strlen(b + 1);
	b1[0] = b2[0] = 1;
	hash1();
	for (ll i = 1; i <= min(len1, len2); i++)
		if (cmp(1, i, len2 - i + 1, len2))
			ans = max(ans, i);
	for (ll i = 1; i <= min(len1, len2); i++)
		if (cmp(len1 - i + 1, len1, 1, i))
			ans = max(ans, i);
	printf("%lld", ans);
	return 0;
}