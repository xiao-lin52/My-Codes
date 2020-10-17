#include<bits/stdc++.h>
#define N 100010
#define lowbit(x) x&(-x)
using namespace std;
struct Trie
{
	long long k,nxt[5*N][52],isWord[5*N];
	void insert(char* str,long long id)
	{
		long long p=0,len=strlen(str);
		for(int i=0;i<len;i++)
			if(str[i]>='A'&&str[i]<='Z')
				if(nxt[p][str[i]-'A'])
					p=nxt[p][str[i]-'A'];
				else
					p=nxt[p][str[i]-'A']=++k;
			else
				if(nxt[p][str[i]-'a'+26])
					p=nxt[p][str[i]-'a'+26];
				else
					p=nxt[p][str[i]-'a'+26]=++k;
		isWord[p]=id;
	}
	long long find(char* str)
	{
		long long p=0,len=strlen(str);
		for(int i=0;i<len;i++)
			if(str[i]>='A'&&str[i]<='Z')
				p=nxt[p][str[i]-'A'];
			else
				p=nxt[p][str[i]-'a'+26];
		return isWord[p];
	}
};
Trie trie;
long long n,ans,b[N];
char a[N];
void update(int x)
{
	for(;x<=n;x+=lowbit(x))
		b[x]++;
}
int query(int x)
{
	int sum=0;
	for(;x>=1;x-=lowbit(x))
		sum+=b[x];
	return sum;
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a);
		trie.insert(a,i);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a);
		int t=trie.find(a);
		ans+=query(n)-query(t);
		update(t);
	}
	printf("%lld",ans);
	return 0;
}
