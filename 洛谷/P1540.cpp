#include<cstdio>
using namespace std;
int n,m,a,head,tail,ans,dl[1010];
int main()
{
	scanf("%d%d",&m,&n);
	head=0;
	tail=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		bool p=0;
		for(int j=head;j<tail;j++)
			if(dl[j]==a)
			{
				p=1;
				break;
			}
		if(!p)
		{
			ans++;
			if(tail-head<m)
			{
				dl[tail++]=a;
			}
			else
			{
				dl[tail++]=a;
				head++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
