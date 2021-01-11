#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
using namespace std;
typedef long long ll;
const ll N = 100+10, inf = 0x3f3f3f3f, mod = 1e9+7;
ll n, k;
struct Matrix
{
	ll mat[N][N];
	void init()
	{
		memset(mat, 0, sizeof(mat));
	}
	Matrix operator * (Matrix a)
	{
		Matrix res;
		res.init();
		rep(i, 1, n)
			rep(k, 1, n)
			{
				ll r = mat[i][k];
				rep(j, 1, n)
					res.mat[i][j] = (res.mat[i][j]+r*a.mat[k][j]%mod)%mod;
			}
		return res;
	}
	Matrix operator ^ (ll k)
	{
		Matrix res, b;
		res.init();
		rep(i, 1, n)
		{
			res.mat[i][i] = 1;
			rep(j, 1, n)
				b.mat[i][j] = mat[i][j];
		}
		while(k)
		{
			if(k&1)
				res = res*b;
			k >>= 1;
			b = b*b;
		}
		return res;
	}
};
Matrix a, ans;
int main()
{
	scanf("%lld%lld", &n, &k);
	rep(i, 1, n)
		rep(j, 1, n)
			scanf("%lld", &a.mat[i][j]);
	ans = a^k;
	rep(i, 1, n)
	{
		rep(j, 1, n)
			printf("%lld ", ans.mat[i][j]);
		printf("\n");
	}
	return 0;
}