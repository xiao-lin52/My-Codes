#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,opt[41][41][7][41];
int judge(int a[],int b[])
{
	if(a[0]>b[0])
		return 1;
	if(a[0]<b[0])
		return 0;
	for(int i=a[0];i>=1;i--)
	{
		if(a[i]>b[i])
			return 1;
		if(a[i]<b[i])
			return 0;
	}
	return 0;
}
void work(int a[],int b[],int des[])
{
	int c[101]={0};
	for(int i=1;i<=a[0];i++)
	{
		for(int j=1;j<=b[0];j++)
		{
			c[i+j-1]+=a[i]*b[j]%10;
			c[i+j]+=a[i]*b[j]/10;
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	}
	for(int i=1;i<=a[0]+b[0]-1;i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if(c[a[0]+b[0]])
		c[0]=a[0]+b[0];
	else
		c[0]=a[0]+b[0]-1;
	if(judge(c,des))
	{
		des[0]=c[0];
		for(int i=1;i<=des[0];i++)
			des[i]=c[i];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&opt[i][i][0][1]);
		opt[i][i][0][0]=1;
	}
	for(int step=1;step<=n-1;step++)
		for(int l=1;l<=n-step;l++)
		{
			int r=l+step;
			for(int k=l;k<=r;k++)
				opt[l][r][0][k-l+1]=opt[r-k+l][r-k+l][0][1];
			opt[l][r][0][0]=r-l+1;
		}
	for(int step=1;step<=n-1;step++)
	{
		for(int l=1;l<=n-step;l++)
		{
			int r=l+step;
			for(int k=l;k<=r-1;k++)
			{
				for(int i=1;i<=m&&i<=r-l;i++)
				{
					for(int j=max(0,i-r+k);j<=min(i-1,k-l);j++)
					{
						work(opt[l][k][j],opt[k+1][r][i-1-j],opt[l][r][i]);
					}
				}
			}
		}
	}
	for(int i=opt[1][n][m][0];i>=1;i--)
		printf("%d",opt[1][n][m][i]);
	return 0;
}
