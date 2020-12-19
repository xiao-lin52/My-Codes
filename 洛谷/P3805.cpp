#include <bits/stdc++.h>
using namespace std;
const int N = 3e7 + 10;
char str[N];
int n, x, y, ans, d[N];
int main()
{
	fread(str+1, 1, 11000010, stdin);
	n = strlen(str + 1);
	for (int i = 2 * n; i >= 1; i -= 2)
	{
		str[i + 1] = '#';
		str[i] = str[i / 2];
	}
	str[1] = '#';
	str[0] = '$';
	str[2 * n + 2] = '^';
	n = strlen(str + 1);
	for (int i = 1; i < n; i++)
	{
		int k = i > y ? 1 : min(y - i, d[x + y - i]);
		while (str[i + k] == str[i - k])
			k++;
		d[i] = k - 1;
		if(i + d[i] > y)
		{
			x = i - d[i];
			y = i + d[i];
		}
		ans = max(ans, d[i]);
	}
	printf("%d", ans);
	return 0;
}