#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 20123
using namespace std;
struct treasure
{
	int p;
	int x;
};
treasure a[10001][101];
int n,m,c,ans,i,j,s[10001];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d%d",&a[i][j].p,&a[i][j].x);
			s[i]+=a[i][j].p;
		}
	scanf("%d",&c);
	i=1;
	j=c+1;
	while(i<=n)
	{
		int t,k=0;
		ans=(ans+a[i][j].x)%mod;
		t=a[i][j].x%s[i];
		t+=s[i];
		while(1)
		{
			if(a[i][j].p)
				k++;
			if(k==t)
				break;
			j++;
			if(j>m)
				j=1;
		}
		i++;
	}
	printf("%d",ans);
	return 0;
}
