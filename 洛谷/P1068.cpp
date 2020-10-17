#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int a[5001][2],i,j,s,k,n,m;
int  main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(i=n-1;i>0;i--)
		for(j=0;j<=i-1;j++)
		{
			if(a[j][1]<a[j+1][1])
			{
				swap(a[j][1],a[j+1][1]);
				swap(a[j][0],a[j+1][0]);
			}
			if(a[j][1]==a[j+1][1]&&a[j][0]>a[j+1][0])
			{
				swap(a[j][1],a[j+1][1]);
				swap(a[j][0],a[j+1][0]);
			}
		}
	s=a[int(floor(m*1.5)-1)][1];
	for(i=0;a[i][1]>=s&&i<n;i++)
		k++;
	printf("%d %d\n",s,k);
	for(i=0;i<k;i++)
		printf("%d %d\n",a[i][0],a[i][1]);
	return 0;
}
