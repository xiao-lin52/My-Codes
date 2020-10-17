#include<cstdio>
using namespace std;
int n,sum,p,visit[20],a[20],num[20][20];
inline void yh()
{
	for(register int i=1;i<=n;i++)
	{
		num[i][1]=1;
		for(register int j=2;j<=i-1;j++)
			num[i][j]=num[i-1][j-1]+num[i-1][j];
		num[i][i]=1;
	}
}
void dfs(int x,int v)
{
	if(v>=sum)
		return;
	for(int i=1;i<=n&&!p;i++)
		if(!visit[i])
		{
			visit[i]=1;
			a[x]=i;
			if(x==n)
			{
				if(v+a[x]*num[n][x]==sum)
				{
					for(int j=1;j<=n;j++)
						printf("%d ",a[j]);
					p=1;
					break;
				}
			}
			else
				dfs(x+1,v+a[x]*num[n][x]);
			visit[i]=0;
		}
}
int main()
{
	scanf("%d%d",&n,&sum);
	yh();
	dfs(1,0);
	return 0;
}
