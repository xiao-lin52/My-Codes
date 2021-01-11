#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10, inf = 0x3f3f3f3f;
int n, m, x, y, t, nxt[N] ,num[100];
char str[N][100];
int gcd(int a, int b)
{
	while(a)
	{
		int t = a;
		a = b%a;
		b = t;
	}
	return b;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", str[i]+1);
	for(y = 1; y <= m; y++)
	{
		int flag = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m-y; j++)
			{
				if(str[i][j] != str[i][j+y])
				{
					flag = 0;
					break;
				}
			}
			if(!flag)
				break;
		}
		if(flag)
			break;
	}
	for(int i = 2, j = 0; i <= n; i++)
	{
		for(int k = 1; k <= y; k++)
			while(str[i][k] != str[j+1][k] && j)
				j = nxt[j];
		int flag = 1;
		for(int k = 1; k <= y; k++)
			if(str[j+1][k] != str[i][k])
				flag = 0;
		if(flag)
			j++;
		nxt[i] = j;
	}
	printf("%d", (n-nxt[n])*y);
	return 0;
}