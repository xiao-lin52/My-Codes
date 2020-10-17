#include<bits/stdc++.h>
using namespace std;
struct Trie
{
	int k,nxt[500010][26],isWord[500010];
	void insert(char* str)
	{
		int p=0,len=strlen(str);
		for(int i=0;i<len;i++)
			if(nxt[p][str[i]-'a'])
				p=nxt[p][str[i]-'a'];
			else
				p=nxt[p][str[i]-'a']=++k;
		isWord[p]=1;
	}
	int find(char* str)
	{
		int p=0,len=strlen(str);
		for(int i=0;i<len;i++)
			if(nxt[p][str[i]-'a'])
				p=nxt[p][str[i]-'a'];
			else
				return 0;
		if(isWord[p])
			return isWord[p]++;
		else
			return 0;
	}
};
Trie trie;
int n,m;
char a[51];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a);
		trie.insert(a);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",a);
		int t=trie.find(a);
		if(t<1)
			printf("WRONG\n");
		if(t==1)
			printf("OK\n");
		if(t>1)
			printf("REPEAT\n");
	}
	return 0;
}
