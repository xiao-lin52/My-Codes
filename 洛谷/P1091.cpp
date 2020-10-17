#include<cstdio>
using namespace std;
int n,m,ans,a[100],opt[100],opt1[100];
int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(a[i]>a[j]&&opt[j]+1>opt[i])
				opt[i]=opt[j]+1;
	for(int i=n-1; i>0; i--)
		for(int j=n-1; j>i; j--)
			if(a[i]>a[j]&&opt1[j]+1>opt1[i])
				opt1[i]=opt1[j]+1;
	for(int i=0; i<n; i++)
	{
		ans=opt[i]+opt1[i]+1;
		if(ans>m) m=ans;
	}
	printf("%d",n-m);
	return 0;
}
