#include<cstdio>
#include<iostream>
using namespace std;
int a[300][5],n,i,j,k,l;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][3]+=a[i][j];
			a[i][4]=i+1;
		}
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j][3]<a[j+1][3])
				for(k=0;k<5;k++)
					swap(a[j][k],a[j+1][k]);
			if(a[j][3]==a[j+1][3]&&a[j][0]<a[j+1][0])
				for(k=0;k<5;k++)
					swap(a[j][k],a[j+1][k]);
			if(a[j][3]==a[j+1][3]&&a[j][0]==a[j+1][0]&&a[j][4]>a[j+1][4])
				for(k=0;k<5;k++)
					swap(a[j][k],a[j+1][k]);
		}
	}
	for(i=0;i<5;i++)
		printf("%d %d\n",a[i][4],a[i][3]);
	return 0;
}
