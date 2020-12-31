#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
struct Segment
{
	int l;
	int r;
	bool operator < (const Segment &a) const
	{
		return l == a.l ? r > a.r : l < a.l;
	}
};
Segment b[N<<1];
int n, x, y, p[N<<1];
char str[N<<1];
int main()
{
	while(scanf("%s", str+1) != EOF)
	{
		y = 0;
		n = strlen(str+1);
		for (int i = 2*n; i >= 1; i -= 2)
		{
			str[i+1] = '#';
			str[i] = str[i/2];
		}
		str[1] = '#';
		str[0] = '$';
		str[2*n+2] = '^';
		for(int i = 1; i <= 2*n+1; i++)
		{
			int k = i > y ? 1 : min(y-i, p[x+y-i]);
			while(str[i+k] == str[i-k])
				k++;
			p[i] = --k;
			if(y < i+k)
			{
				x = i-k;
				y = i+k;
			}
			b[i].l = i-k;
			b[i].r = i+k;
		}
		sort(b+1, b+2+2*n);
		int ans = 0, flag = b[1].r, j = 2;
		while(j <= 2*n+1)
		{
			int mx = 0;
			while(b[j].l <= flag && j <= 2*n+1)
			{
				mx = max(mx, b[j].r);
				j++;
			}
			if(j <= 2*n+1)
				ans++;
			flag = mx;
		}
		printf("%d\n", ans);
		memset(str, 0, sizeof(str));
		memset(p, 0, sizeof(p));
		memset(b, 0, sizeof(b));
	}
	return 0;
}