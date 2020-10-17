#include<cstdio>
#include<cmath>
using namespace std;
int n,visit[20];
double ans=100000000.0,w[20][20],x[20],y[20];
void dfs(int x,int v,double s)
{
	if(s>=ans)
		return;
	for(int i=1;i<=n;i++)
		if(!visit[i])
		{
			if(x==n)
			{
				if(ans>s+w[v][i])
					ans=s+w[v][i];
				return;
			}
			else
			{
				visit[i]=1;
				dfs(x+1,i,s+w[v][i]);
				visit[i]=0;
			}
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
		for(int j=0;j<i;j++)
			w[j][i]=w[i][j]=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
	}
	dfs(1,0,0);
	printf("%.2lf",ans);
	return 0;
}
