#include<cstdio>
using namespace std;
int ans,a[7],opt[1001],w[7]={0,1,2,3,5,10,20};
int main()
{
	for(int i=1;i<=6;i++)
		scanf("%d",&a[i]);
	opt[0]=1;
	for(int i=1;i<=6;i++)
		for(int j=1000;j>=w[i];j--)
			for(int k=1;k<=a[i]&&k*w[i]<=j;k++)
				if(opt[j-k*w[i]])
					opt[j]=1;
	for(int i=1;i<=1000;i++)
		ans+=opt[i];
	printf("Total=%d",ans);
	return 0;
}