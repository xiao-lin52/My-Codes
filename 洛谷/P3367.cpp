#include<cstdio>
using namespace std;
int n,m,z,x,y,f[10001];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)
			f[find(x)]=f[find(y)];
		else
			if(find(f[x])==find(f[y]))
				printf("Y\n");
			else
				printf("N\n");
	}
	return 0;
}
