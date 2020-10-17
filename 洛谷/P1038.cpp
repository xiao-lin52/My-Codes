#include<cstdio>
#include<queue>
#define maxn 1000000000
using namespace std;
int n,m,c[101],u[101],in[101],out[101],a[101][101];
queue<int>q;
void topo()
{
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(c[x]<=0)
			continue;
		for(int i=1;i<=n;i++)
			if(a[x][i]!=maxn)
			{
				c[i]+=a[x][i]*c[x];
				in[i]--;
				if(!in[i])
				{
					c[i]-=u[i];
					q.push(i);
				}
			}
	}
	int flag=0;
	for(int i=1;i<=n;i++)
		if(!out[i])
		{
			if(c[i]>0)
			{
				flag=1;
				printf("%d %d\n",i,c[i]);
			}
		}
	if(!flag)
		printf("NULL");
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=maxn;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&c[i],&u[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
		in[y]++;
		out[x]++;
	}
	topo();
	return 0;
}
