#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int n,b,sum=0,a[20001];
int main()
{
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>=b)
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}
