#include<cstdio>
#define N 1010
using namespace std;
int t,n,cnt,a[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)
				cnt++;
		}
		if(cnt&1)
			printf("rabbit\n");
		else
			printf("hamster\n");
	}
	return 0;
}
