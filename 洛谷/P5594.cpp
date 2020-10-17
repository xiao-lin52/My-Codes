#include<cstdio>
using namespace std;
int n,m,k,a,b[1001][1001],s[1001];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a);
			b[a][++s[a]]=j;
		}
	for(int i=1;i<=k;i++)
	{
		int ans=0,t[1001]={0};
		for(int j=1;j<=s[i];j++)
			if(!t[b[i][j]])
			{
				ans++;
				t[b[i][j]]=1;
			}
		printf("%d ",ans);
	}
	return 0;
}
