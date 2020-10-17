#include<cstdio>
using namespace std;
struct queue
{
	int v;
	int w;
};
queue a1[1000001],a2[1000001];
int n,m,x,head1=1,tail1,head2=1,tail2,ans1[1000001],ans2[1000001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		while(head1<=tail1&&x>a1[tail1].v)
			tail1--;
		tail1++;
		a1[tail1].w=i;
		a1[tail1].v=x;
		while(head2<=tail2&&x<a2[tail2].v)
			tail2--;
		tail2++;
		a2[tail2].w=i;
		a2[tail2].v=x;
		if(i>=m)
		{
			while(i-a1[head1].w+1>m)
				head1++;
			while(i-a2[head2].w+1>m)
				head2++;
			ans1[i-m+1]=a1[head1].v;
			ans2[i-m+1]=a2[head2].v;
		}
	}
	for(int i=1;i<=n-m+1;i++)
		printf("%d ",ans2[i]);
	printf("\n");
	for(int i=1;i<=n-m+1;i++)
		printf("%d ",ans1[i]);
	return 0;
}
