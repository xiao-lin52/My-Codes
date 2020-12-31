#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s, ans, bas[100];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &s);
		for(int j = 50; j >= 0; j--)
			if((s>>j)&1)
				if(!bas[j])
				{
					bas[j] = s;
					break;
				}
				else
					s ^= bas[j];
	}
	for(int i = 50; i >= 0; i--)
		if((ans^bas[i]) > ans)
			ans ^= bas[i];
	printf("%lld", ans);
	return 0;
}