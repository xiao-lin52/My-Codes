#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int n,s=1,a[200001],m1,m2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	m1=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			s++;
		if(s==2)
			m2=a[i];
		if(s==3)
		{
			printf("%d",max(a[i],m1%m2));
			return 0;
		}
	}
	printf("-1");
	return 0;
}
