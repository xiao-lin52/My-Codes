#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1e6+10, inf = 0x3f3f3f3f;
int n, top, len1, len2, nxt[N], num[N], pos[N];
char s[N], t[N];
int main()
{
	scanf("%s", s+1);
	scanf("%s", t+1);
	len1 = strlen(s+1);
	len2 = strlen(t+1);
	for(int i = 2, j = 0; i <= len2; i++)
	{
		while(t[j+1] != t[i] && j)
			j = nxt[j];
		if(t[j+1] == t[i])
			j++;
		nxt[i] = j;
	}
	for(int i = 1, j = 0; i <= len1; i++)
	{
		while(t[j+1] != s[i] && j)
			j = nxt[j];
		if(t[j+1] == s[i])
			j++;
		num[i] = j;
		pos[++top] = i;
		if(j == len2)
		{
			top -= len2;
			j = num[pos[top]];
		}
	}
	rep(i, 1, top)
		printf("%c", s[pos[i]]);
	return 0;
}