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
const int N = 1e5+10, inf = 0x3f3f3f3f;
int n, tot, top, len[N], nxt[N][30], fail[N], e[N], num[N];
char s[N], t[N], cha[N];
void insert(int x, char str[])
{
	int p = 0;
	rep(i, 1, strlen(str+1))
	{
		int q = str[i]-'a'+1;
		if(!nxt[p][q])
			nxt[p][q] = ++tot;
		p = nxt[p][q];
	}
	e[p] = x;
}
void build()
{
	queue<int> q;
	rep(i, 1, 26)
		if(nxt[0][i])
			q.push(nxt[0][i]);
	while(q.size())
	{
		int p = q.front();
		q.pop();
		rep(i, 1, 26)
			if(nxt[p][i])
				fail[nxt[p][i]] = nxt[fail[p]][i], q.push(nxt[p][i]);
			else
				nxt[p][i] = nxt[fail[p]][i];
	}
}
void query()
{
	int p = 0;
	rep(i, 1, strlen(s+1))
	{
		int q = s[i]-'a'+1;
		p = nxt[p][q];
		num[++top] = p;
		cha[top] = q+'a'-1;
		if(e[p])
		{
			top -= len[e[p]];
			p = num[top];
		}
	}
}
int main()
{
	scanf("%s%d", s+1, &n);
	rep(i, 1, n)
	{
		scanf("%s", t+1);
		insert(i, t);
		len[i] = strlen(t+1);
	}
	build();
	query();
	rep(i, 1, top)
		printf("%c", cha[i]);
	return 0;
}