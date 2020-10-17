#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int n,ans,a[501][501],visit[501];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			a[i][j]=a[j][i];
	for(int i=1;i<=n;i++)
		sort(a[i]+1,a[i]+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(ans<a[i][2])
			ans=a[i][2];
	printf("1\n%d",ans);
	return 0;
}
