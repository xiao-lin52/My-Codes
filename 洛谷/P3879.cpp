#include<bits/stdc++.h>
#define SIZE 500010
using namespace std;
struct Trie
{
	int k,nxt[SIZE][26];
	vector<int> isWord[SIZE];
	void insert(char* str,int x)
	{
		int p=0,len=strlen(str);
		for(int i=0;i<len;i++)
			if(nxt[p][str[i]-'a'])
				p=nxt[p][str[i]-'a'];
			else
				p=nxt[p][str[i]-'a']=++k;
		if(isWord[p].empty()||isWord[p].back()!=x)
			isWord[p].push_back(x);
	}
	void find(char* str)
	{
		int p=0,len=strlen(str);
		for(int i=0;i<len;i++)
			if(nxt[p][str[i]-'a'])
				p=nxt[p][str[i]-'a'];
			else
			{
				printf("\n");
				return;
			}
		for(int i=0;i<isWord[p].size();i++)
			printf("%d ",isWord[p][i]);
		printf("\n");
	}
};
Trie trie;
int n,m,l;
char a[30];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l);
		for(int j=1;j<=l;j++)
		{
			scanf("%s",a);
			trie.insert(a,i);
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",a);
		trie.find(a);
	}
	return 0;
}
