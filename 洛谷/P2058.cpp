#include<cstdio>
using namespace std;
struct passenger
{
	int t;
	int g;
};
passenger a[500000];
int n,s,head,tail,book[100001]= {};
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int tmp1,tmp2;
		scanf("%d%d",&tmp1,&tmp2);
		for(int j=1; j<=tmp2; j++)
		{
			scanf("%d",&a[tail].g);
			a[tail].t=tmp1;
			book[a[tail].g]++;
			if(book[a[tail].g]==1)
				s++;
			tail++;
		}
		while(a[head].t<=tmp1-86400)
		{
			book[a[head].g]--;
			if(book[a[head].g]==0)
				s--;
			head++;
		}
		printf("%d\n",s);
	}
	return 0;
}