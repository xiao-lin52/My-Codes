#include<cstdio>
#include<algorithm>
using namespace std;
int n,s,a,b,k,sum,num[5010];
int main()
{
	scanf("%d%d%d%d",&n,&s,&a,&b);
	for(int i=1;i<=n;i++)
	{
		int e,f;
		scanf("%d%d",&e,&f);
		if(e<=a+b) num[++k]=f;
	}
	sort(num+1,num+1+k);
	int i=0,j=0;
	while(i<=s)
	{
		i+=num[++j];
		sum++;
		if(j>k) break;
	}
	printf("%d",sum-1);
	return 0;
}
