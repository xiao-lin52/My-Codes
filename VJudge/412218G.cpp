#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
struct Trie
{
	int isWord, val, siz, id, son[30];
	void cal()
	{
		for(int i = 1; i <= 26; i++)
			val = (val<<1)+(son[i] ? 1 : 0);
	}
	bool operator < (const Trie &a) const
	{
		return siz == a.siz ? (val == a.val ? isWord < a.isWord : val < a.val) : siz < a.siz;
	}
};
Trie trie[N<<2], c[N<<2];
int n, rt, tot, cnt, col[N<<2];
char a[N];
void push_up(int p)
{
	trie[p].siz = 1;
	for(int i = 1; i <= 26; i++)
		trie[p].siz += trie[trie[p].son[i]].siz;
}
void insert(int &p, int x)
{
	if(!p)
	{
		p = ++tot;
		trie[p].id = p;
		trie[p].siz = 1;
	}
	if(a[x] == '\0')
	{
		trie[p].isWord = 1;
		return;
	}
	insert(trie[p].son[a[x]-'a'+1], x+1);
	push_up(p);
}
int check(int x, int y)
{
	for(int i = 1; i <= 26; i++)
		if(col[trie[x].son[i]] != col[trie[y].son[i]])
			return 0;
	return 1;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		memset(a, 0, sizeof(a));
		scanf("%s", a+1);
		insert(rt, 1);
	}
	for(int i = 1; i <= tot; i++)
	{
		trie[i].cal();
		c[i] = trie[i];
	}
	sort(c+1, c+1+tot);
	for(int i = 1; i <= tot; i++)
	{
		int j = i-1, flag = 0;
		while(c[j].val == c[i].val && c[j].siz == c[i].siz && c[j].isWord == c[i].isWord && j >= 1)
			if(check(c[j].id, c[i].id))
			{
				col[c[i].id] = col[c[j].id];
				flag = 1;
				break;
			}
			else
				j--;
		if(!flag)
			col[c[i].id] = ++cnt;
	}
	printf("%d", cnt);
	return 0;
}