#include<cstdio>
using namespace std;
int n,k,ans,w[100];
void dfs(int s,int last,int x)
{
	if(x==k)
	{
		if(n-s>=last)
			ans++;
		return;
	}
	for(int i=last;i<=(n-s)/(k-x);i++)
	{
		w[x]=i;
		dfs(s+i,i,x+1);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	dfs(0,1,1);
	printf("%d",ans);
	return 0;
}
