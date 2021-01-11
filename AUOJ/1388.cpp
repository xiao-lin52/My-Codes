#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define naohuo pair<int, int>
#define mp make_pair
using namespace std;
typedef double ll;
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
bool check(double x)
{
	return (double)(int)x == x;
}
naohuo a[N];
ll b, k;
int t, n;
map<naohuo, int> p;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		p.clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i].first, &a[i].second);
			p[a[i]] = 1;
		}
		int flag = 0;
		for(int i = 2; i <= n; i++)
		{
			int res = 1;
			if(a[i].first == a[1].first)
			{
				b = (a[1].second+a[i].second)/2.0;
				for(int j = 1; j <= n; j++)
				{
					if(!check(2.0*b-a[j].second*1.0))
					{
						res = 0;
						break;
					}
					naohuo tmp = mp(a[j].first, 2.0*b-a[j].second);
					if(!((tmp != a[j] && p[tmp] >= 1) || (tmp == a[j] && p[tmp] >= 2)))
					{
						res = 0;
						break;
					}
				}
			}
			else if(a[i].second == a[1].second)
			{
				b = (a[1].first+a[i].first)/2.0;
				for(int j = 1; j <= n; j++)
				{
					if(!check(2.0*b-a[j].first*1.0))
					{
						res = 0;
						break;
					}
					naohuo tmp = mp(2.0*b-a[j].first, a[j].second);
					if(!((tmp != a[j] && p[tmp] >= 1) || (tmp == a[j] && p[tmp] >= 2)))
					{
						res = 0;
						break;
					}
				}
			}
			else
			{
				k = -1.0/((a[i].second-a[1].second)/(a[i].first-a[1].first));
				b = (a[1].second+a[i].second-k*(a[1].first+a[i].first))/2.0;
				for(int j = 1; j <= n; j++)
				{
					ll k1 = -1.0/k, b1 = a[j].second-k1*a[j].first;
					pii t1 = mp((b-b1)/(k1-k), (b-b1)/(k1-k)*k+b);
					if(!check(2.0*t1.first-a[j].first*1.0) || !check(2.0*t1.second-a[j].second*1.0))
					{
						res = 0;
						break;
					}
					naohuo tmp = mp((int)2.0*t1.first-a[j].first, (int)2.0*t1.second-a[j].second);
					if(!((tmp != a[j] && p[tmp] >= 1) || (tmp == a[j] && p[tmp] >= 2)))
					{
						res = 0;
						break;
					}
				}
			}
			if(res)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}