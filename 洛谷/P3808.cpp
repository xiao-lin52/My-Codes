#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10, inf = 0x3f3f3f3f;
int n, tot, ans, nxt[N][30], fail[N], isWord[N];
char t[N];
void insert(char str[])
{
	int len = strlen(str+1), p = 0;
	for(int i = 1; i <= len; i++)
	{
		int s = str[i]-'a'+1;
		if(!nxt[p][s])
			nxt[p][s] = ++tot;
		p = nxt[p][s];
	}
	isWord[p]++;
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
		int s = t[i]-'a'+1;
		p = nxt[p][s];
		if(isWord[p])
		{
			ans += isWord[p];
			isWord[p] = 0;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", t+1);
		insert(t);
	}
	build();
	scanf("%s", t+1);
	query();
	printf("%d", ans);
	return 0;
}