#include<cstdio>
#include<cstring>
using namespace std;
int n,p,ans,a[100000][11];
void dfs(int x,int sum)
{
	if(x==10)
	{
		if(n-sum>=1&&n-sum<=3)
		{
			a[ans+1][10]=n-sum;
			ans++;
			memcpy(a[ans+1],a[ans],sizeof(a[ans-1]));
		}
		return;
	}
	if(sum>=n)
		return;
	for(int i=1;i<=3;i++)
	{
		a[ans+1][x]=i;
		dfs(x+1,sum+i);
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1,0);
	if(ans)
	{
		printf("%d\n",ans);
		for(int i=1;i<=ans;i++)
		{
			for(int j=1;j<=10;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
	}
	else
		printf("0");
	return 0;
}