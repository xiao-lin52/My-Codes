#include<cstdio>
#include<algorithm>
using namespace std;
int n,j,s,i,l,a[101];
bool v[101];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n-2;i++)
		for(j=i+1;j<=n-1;j++)
			for(l=j+1;l<=n;l++)
				if(a[j]+a[i]==a[l]&&!v[l])
				{
					s++;
					v[l]=true;
				}
	printf("%d",s);
	return 0;
}