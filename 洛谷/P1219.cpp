#include<cstdio>
using namespace std;
int n,sum,ans[15];
bool heng[20],shu[20],xie[40],fxie[40];
void dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!heng[x]&&!shu[i]&&!xie[x+i]&&!fxie[x-i+n])
		{
			heng[x]=shu[i]=xie[x+i]=fxie[x-i+n]=1;
			ans[x]=i;
			if(x==n)
			{
				sum++;
				if(sum<=3)
				{
					for(int j=1;j<=n;j++)
						printf("%d ",ans[j]);
					printf("\n");
				}
			}
			else
				dfs(x+1);
			heng[x]=shu[i]=xie[x+i]=fxie[x-i+n]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	printf("%d",sum);
	return 0;
}
