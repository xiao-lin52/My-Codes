#include<bits/stdc++.h>
using namespace std;
int t,n,x,a[100],b[100],vis[100];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=n;i>=1;i--)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
		{
			int flag=0;
			for(int j=1;j<=n;j++)
				if(a[i]+b[j]<=x&&!vis[j])
				{
					vis[j]=flag=1;
					break;
				}
			if(!flag)
			{
				printf("No\n");
				goto l;
			}
		}
		printf("Yes\n");
		l:;
	}
	return 0;
}
