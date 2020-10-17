#include<cstdio>
using namespace std;
struct queue
{
	int v;
	int w;
};
queue a[1000001];
int n,m,x,head=1,tail;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		while(head<=tail&&x>a[tail].v)
			tail--;
		tail++;
		a[tail].w=i;
		a[tail].v=x;
		if(i>=m)
		{
			while(i-a[head].w+1>m)
				head++;
			printf("%d\n",a[head].v);
		}
	}
	return 0;
}