#include<cstdio>
using namespace std;
int n,m,q,f[20001];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1; i<=n; i++)
		f[i]=i;
	for(int i=1; i<=m; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		f[find(a)]=f[find(b)];
	}
	for(int i=1; i<=q; i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(find(c)==find(d))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
