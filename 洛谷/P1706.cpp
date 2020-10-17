#include<cstdio>
#include<iostream>
using namespace std;
int n,a[10],visit[10];
void dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!visit[i])
		{
			a[x]=i;
			visit[i]=1;
			if(x==n)
			{
				for(int j=1;j<=n;j++)
					printf("%5d",a[j]);
				cout<<endl;
			}
			else
				dfs(x+1);
			visit[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}
