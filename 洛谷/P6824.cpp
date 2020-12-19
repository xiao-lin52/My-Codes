#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+10;
int n,k,a;
struct Trie
{
	int tot=1,son[N][2],sum[N];
	void insert(int x)
	{
		int p=1;
		for(int i=20;i>=0;i--)
		{
			int s=((x>>i)&1);
			if(!son[p][s])
				son[p][s]=++tot;
			p=son[p][s];
			sum[p]++;
		}
	}
	int query(int p,int i)
	{
		if(p==0)
			return 0;
		if(i==-1)
			return sum[p];
		int s=((k>>i)&1);
		if(s)
			return max(sum[son[p][0]]+query(son[p][1],i-1),sum[son[p][1]]+query(son[p][0],i-1));
		else
			return max(query(son[p][0],i-1),query(son[p][1],i-1));
	}
};
Trie trie;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		trie.insert(a);
	}
	printf("%d",trie.query(1,20));
	return 0;
}