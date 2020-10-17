#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,p,a[5001],b[1000001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			b[a[j]-a[i]]=1;
	for(int i=n;i<=1000000&&!p;i++)
	{
		p=1;
		for(int j=i;j<=a[n]-a[1];j+=i)
			if(b[j])
				if(j%i==0)
				{
					p=0;
					break;
				}
		if(p) printf("%d",i);
	}
	return 0;
}
