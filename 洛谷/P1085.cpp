#include<cstdio>
#include<iostream>
using namespace std;
int a[7][4];
int main()
{
	for(int i=0;i<7;i++)
	{
		scanf("%d%d",&a[i][1],&a[i][2]);
		a[i][0]=i+1;
		a[i][3]=a[i][1]+a[i][2];
	}
	for(int i=6;i>0;i--)
		for(int j=0;j<i;j++)
			if(a[j][3]>a[j+1][3]||(a[j][3]==a[j+1][3]&&a[j][0]<a[j+1][0]))
			{
				swap(a[j][3],a[j+1][3]);
				swap(a[j][0],a[j+1][0]);
			}
	if(a[6][3]<=8)
		printf("0");
	else
		printf("%d",a[6][0]);
	return 0;
}
