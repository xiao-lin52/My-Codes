#include<cstdio>
using namespace std;
int t,m,n,ans;
void dfs(int x,int s,int last)
{
	for(int i=last;i<=s;i++)
		if(x==n)
		{
			ans++;
			break;
		}
		else
			dfs(x+1,s-i,i);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d",&m,&n);
		dfs(1,m,0);
		printf("%d\n",ans);
	}
	return 0;
}