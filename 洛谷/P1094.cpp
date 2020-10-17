#include<cstdio>
#include<algorithm>
using namespace std;
int w,n,ans,head,tail,p[30001];
int main()
{
	scanf("%d%d",&w,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	sort(p+1,p+1+n);
	head=1;
	tail=n;
	while(head<=tail)
		if(p[head]+p[tail]<=w&&head<tail)
		{
			ans++;
			head++;
			tail--;
		}
		else
			if(head==tail)
			{
				ans++;
				break;
			}
			else
			{
				ans++;
				tail--;
			}
	printf("%d",ans);
	return 0;
}
