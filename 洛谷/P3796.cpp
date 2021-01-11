#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10, inf = 0x3f3f3f3f, SIZE = 3e5+10;
struct Answer
{
	int val;
	int id;
	bool operator < (const Answer x) const
	{
		return val == x.val ? id < x.id : val > x.val;
	}
};
Answer ans[200];
int n, tot, nxt[SIZE][30], e[SIZE], num[SIZE], fail[SIZE];
char s[200][100], t[N];
void insert(int x, char str[])
{
	int len = strlen(str+1), p = 0;
	for(int i = 1; i <= len; i++)
	{
		if(!nxt[p][str[i]-'a'+1])
			nxt[p][str[i]-'a'+1] = ++tot;
		p = nxt[p][str[i]-'a'+1];
	}
	e[p] = x;
}
void build()
{
	queue<int> q;
	for(int i = 1; i <= 26; i++)
		if(nxt[0][i])
			q.push(nxt[0][i]);
	while(q.size())
	{
		int p = q.front();
		q.pop();
		for(int i = 1; i <= 26; i++)
			if(nxt[p][i])
			{
				fail[nxt[p][i]] = nxt[fail[p]][i];
				q.push(nxt[p][i]);
			}
			else
				nxt[p][i] = nxt[fail[p]][i];
	}
}
void query()
{
	int len = strlen(t+1), p = 0;
	for(int i = 1; i <= len; i++)
	{
		p = nxt[p][t[i]-'a'+1];
		for(int j = p; j; j = fail[j])
			num[j]++;
	}
	for(int i = 1; i <= tot; i++)
		if(e[i])
			ans[e[i]].val = num[i];
}
int main()
{
	while(scanf("%d", &n) && n)
	{
		tot = 0;
		memset(ans, 0, sizeof(ans));
		memset(e, 0, sizeof(e));
		memset(nxt, 0, sizeof(nxt));
		memset(fail, 0, sizeof(fail));
		memset(num, 0, sizeof(num));
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", s[i]+1);
			insert(i, s[i]);
			ans[i].id = i;
		}
		scanf("%s", t+1);
		build();
		query();
		sort(ans+1, ans+1+n);
		printf("%d\n%s\n", ans[1].val, s[ans[1].id]+1);
		for(int i = 2; i <= n; i++)
			if(ans[i].val == ans[i-1].val)
				printf("%s\n", s[ans[i].id]+1);
			else
				break;
	}
	return 0;
}