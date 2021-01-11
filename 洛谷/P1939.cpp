#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
using namespace std;
typedef long long ll;
const int N = 1e5+10, inf = 0x3f3f3f3f, mod = 1e9+7;
struct Matrix
{
	ll mat[4][4], h, l;
	void init()
	{
		memset(mat, 0, sizeof(mat));
	}
	Matrix operator * (Matrix a)
	{
		Matrix res;
		res.init();
		res.h = h;
		res.l = a.l;
		rep(i, 1, h)
			rep(k, 1, l)
			{
				ll t = mat[i][k];
				rep(j, 1, a.l)
					res.mat[i][j] = (res.mat[i][j]+a.mat[k][j]*t%mod)%mod;
			}
		return res;
	}
	Matrix operator ^ (ll k)
	{
		Matrix res, b;
		res.init();
		res.h = res.l = b.h = b.l = 3;
		res.mat[1][1] = res.mat[2][2] = res.mat[3][3] = 1;
		memcpy(b.mat, mat, sizeof(mat));
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
Matrix a, f, ans;
ll n, q;
int main()
{
	scanf("%lld", &n);
	a.h = 1;
	a.l = 3;
	f.l = f.h = 3;
	a.mat[1][1] = a.mat[1][2] = a.mat[1][3] = 1;
	f.mat[1][1] = f.mat[1][2] = f.mat[2][3] = f.mat[3][1] = 1;
	rep(i, 1, n)
	{
		scanf("%lld", &q);
		ans = a*(f^(q-1));
		printf("%lld\n", ans.mat[1][3]);
	}
	return 0;
}