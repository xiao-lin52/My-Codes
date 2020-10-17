#include<cstdio>
#include<iostream>
using namespace std;
int a[100001],n;
void msort(int z,int y)
{
	int t,i,j;
	i=z;
	j=y;
	swap(a[z],a[(z+y)/2]);
	t=a[z];
	while(i<j)
	{
		while(a[j]>t&&i<j)
			j--;
		if(i<j)
		{
			a[i]=a[j];
			i++;
		}
		while(a[i]<t&&i<j)
			i++;
		if(i<j)
		{
			a[j]=a[i];
			j--;
		}
	}
	a[i]=t;
	if(z<i-1)
		msort(z,i-1);
	if(i+1<y)
		msort(i+1,y);
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
		scanf("%d",&a[i]);
	msort(1,n);
	for(i=1; i<=n; i++)
		printf("%d ",a[i]); 
	return 0;
}

