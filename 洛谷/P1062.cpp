#include<cstdio>
using namespace std;
int k,n,w=1;
long long s=1,opt[2000];
int main()
{
	scanf("%d%d",&k,&n);
	opt[1]=1;
	while(w<n)
	{
		for(int i=1;opt[i]<s;i++)
			opt[++w]=s+opt[i];
		s*=k;
		opt[++w]=s;
	}
	printf("%lld",opt[n]);
	return 0;
}
