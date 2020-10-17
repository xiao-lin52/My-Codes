#include<cstdio>
#include<cmath>
using namespace std;
int a[21][20],i,j,k,m,n,s,t,maxn,maxi,maxj,b,c;
int main()
{
	scanf("%d%d%d",&m,&n,&k);
	for(i=1;i<=m;i++)
		for(j=0;j<=n-1;j++)
			scanf("%d",&a[i][j]);
	for(;;)
	{
		for(i=1;i<=m;i++)
			for(j=0;j<=n-1;j++)
				if(a[i][j]>maxn)
				{
					maxn=a[i][j];
					maxi=i;
					maxj=j;
				}
		if(s==0)
			c=maxj;
		if(abs(maxi-b)+abs(maxj-c)+t+maxi+1>k)
			break;
		else
		{
			t+=abs(maxi-b)+abs(maxj-c)+1;
			s+=maxn;
			b=maxi;
			c=maxj;
			a[b][c]=maxn=0;
		}
	}
	printf("%d",s);
	return 0;
}
