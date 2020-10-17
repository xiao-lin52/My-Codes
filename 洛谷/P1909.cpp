#include<cstdio>
using namespace std;
int main()
{
	int t,i,j,n,a[3][3];
	scanf("%d",&n);
	for(i=0;i<=2;i++)
		for(j=0;j<=1;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<=2;i++)
	{
		if(n%a[i][0]!=0&&n/a[i][0]*a[i][0]<n)
			a[i][2]=(n/a[i][0]+1)*a[i][1];
		else
			a[i][2]=(n/a[i][0])*a[i][1];
	}
	for(i=0;i<=2;i++)
		for(j=i+1;j<=2;j++)
			if(a[i][2]>a[j][2])
			{
				t=a[i][2];
				a[i][2]=a[j][2];
				a[j][2]=t;
			}
	printf("%d",a[0][2]);
	return 0;
}