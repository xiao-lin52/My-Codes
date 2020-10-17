#include<cstdio>
using namespace std;
int n,m,f[1001];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
int main()
{
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			f[find(a)]=f[find(b)];
		}
		int s=0,v[1001]={0};
		for(int i=1;i<=n;i++)
		{
			int t=find(i);
			if(!v[t])
			{
				v[t]=1;
				s++;
			}
		}
		printf("%d\n",s-1);
	}
	return 0;
}
