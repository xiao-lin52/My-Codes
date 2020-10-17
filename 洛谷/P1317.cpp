#include<cstdio>
using namespace std;
int n,s,k,a[10001],b[10001];
int main()
{
	scanf("%d",&n);
	k=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
		if(a[i]==a[i+1])
		{
			b[i+1]=1;
			k--;
		}
	for(int i=1;i<=k;i++)
	{
		int j=i;
		while(b[j])
			j++;
		a[i]=a[j];
		b[j]=1;
	}
	for(int i=2;i<=k-1;i++)
		if(a[i-1]>a[i]&&a[i]<a[i+1])
			s++;
	printf("%d",s);
	return 0;
}
