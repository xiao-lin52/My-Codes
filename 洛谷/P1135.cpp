#include<cstdio>
using namespace std;
struct bfs
{
	int x;
	int s;
};
bfs a[10000];
int n,b,k[210],visit[210],tail,head;
int main()
{
	scanf("%d%d%d",&n,&a[0].x,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	visit[a[0].x]=1;
	head=0;
	tail=1;
	if(a[0].x==b)
	{
		printf("0");
		return 0;
	}
	while(head<tail)
	{
		int nx;
		for(int i=-1;i<=1;i+=2)
		{
			nx=a[head].x+i*k[a[head].x];
			if(nx<=n&&nx>=1&&!visit[nx])
			{
				a[tail].x=nx;
				a[tail].s=a[head].s+1;
				visit[nx]=1;
				if(nx==b)
				{
					printf("%d",a[tail].s);
					return 0;
				}
				tail++;
			}
		}
		head++;
	}
	printf("-1");
	return 0;
}
