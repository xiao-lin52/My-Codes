#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
using namespace std;
typedef long long ll;
const int N = 1e6+10, inf = 0x3f3f3f3f;
int n, tot, nxt[N][30], fail[N], tag[N], match[N];
char s[N], t[N<<1];
vector<int> edge[N];
void dfs(int u)
{
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		dfs(v);
		tag[u] += tag[v];
	}
}
void insert(int x, char str[])
{
	int p = 0;
	rep(i, 1, strlen(str+1))
	{
		int s = str[i]-'a'+1;
		if(!nxt[p][s])
			nxt[p][s] = ++tot;
		p = nxt[p][s];
	}
	match[x] = p;
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
	rep(i, 1, tot)
		edge[fail[i]].push_back(i);
}
void query()
{
	int p = 0;
	rep(i, 1, strlen(t+1))
	{
		int s = t[i]-'a'+1;
		p = nxt[p][s];
		tag[p]++;
	}
	dfs(0);
}
int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
	{
		scanf("%s", s+1);
		insert(i, s);
		s[0] = 'z'+1;
		strcat(t+1, s);
	}
	build();
	query();
	rep(i, 1, n)
		printf("%d\n", tag[match[i]]);
	return 0;
}