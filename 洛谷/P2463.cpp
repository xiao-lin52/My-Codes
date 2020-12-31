#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, inf = INT_MAX;
int n, l = 0, r = inf, p, m[N], str[N][N], nxt[1010][N];
int check(int x, int y)
{
	for(int i = 1; i <= n; i++)
	{
		int flag = 0;
		if(i == p)
			continue;
		for(int j = 1, k = x-1; j <= m[i]; j++)
		{
			while(str[p][k+1] != str[i][j] && k > x-1)
				k = nxt[x][k];
			if(str[p][k+1] == str[i][j])
				k++;
			if(k == y)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &m[i]);
		for(int j = 1; j <= m[i]; j++)
		{
			scanf("%d", &str[i][j]);
			str[i][j-1] = str[i][j]-str[i][j-1];
		}
		m[i]--;
		if(m[i] < r)
		{
			r = m[i];
			p = i;
		}
	}
	for(int i = 1; i <= m[p]; i++)
	{
		fill(nxt[i], nxt[i]+m[p]+1, i-1);
		for(int j = i+1, k = i-1; j <= m[p]; j++)
		{
			while(str[p][k+1] != str[p][j] && k > i-1)
				k = nxt[i][k];
			if(str[p][k+1] == str[p][j])
				k++;
			nxt[i][j] = k;
		}
	}
	while(l < r)
	{
		int len = (l+r+1)>>1;
		for(int i = 1; i <= m[p]-len+1; i++)
			if(check(i, i+len-1))
			{
				l = len;
				goto x;
			}
		r = len-1;
		x:;
	}
	printf("%d", l+1);
	return 0;
}