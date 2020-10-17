#include<cstdio>
#include<cmath>
using namespace std;
int n,k,ans,x[21],visit[21];
bool prime(int y)
{
	for(int i=2; i<sqrt(y); i++)
		if(y%i==0)
			return false;
	return true;
}
void dfs(int step,int last,int sum)
{
	for(int i=last+1; i<=n; i++)
		if(!visit[i])
			if(step!=k)
			{
				visit[i]=1;
				dfs(step+1,i,sum+x[i]);
				visit[i]=0;
			}
			else if(prime(sum+x[i]))
				ans++;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",&x[i]);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
