#include<bits/stdc++.h>
#define N 500010
using namespace std;
struct Trie
{
	int k,nxt[N][2],isWord[N],f[N];
	void insert(int* str,int len)
	{
		int p=0;
		for(int i=1;i<=len;i++)
		{
			if(nxt[p][str[i]])
				p=nxt[p][str[i]];
			else
				p=nxt[p][str[i]]=++k;
			f[p]++;
		}
		isWord[p]++;
	}
	int find(int* str,int len)
	{
		int p=0,sum=0,flag=1;
		for(int i=1;i<=len;i++)
		{
			sum+=isWord[p];
			if(nxt[p][str[i]])
				p=nxt[p][str[i]];
			else
			{
				flag=0;
				break;
			}
		}
		if(flag)
			sum+=f[p];
		return sum;
	}
};
Trie trie;
int n,m,a[10010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
			scanf("%d",&a[j]);
		trie.insert(a,c);
	}
	for(int i=1;i<=m;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
			scanf("%d",&a[j]);
		printf("%d\n",trie.find(a,c));
	}
	return 0;
}
