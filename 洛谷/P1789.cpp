#include<cstdio>
using namespace std;
int n,m,k,sum,b[201][201];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=-2;j<=2;j++)
			if(x+j<=n&&x+j>=1&&y+j<=n&&y+j>=1)
			{
				if(!b[x+j][y])
					sum++;
				b[x+j][y]=1;
				if(!b[x][y+j])
					sum++;
				b[x][y+j]=1;
			}
		for(int j=-1;j<=1;j+=2)
			for(int l=-1;l<=1;l+=2)
				if(x+j<=n&&x+j>=1&&y+j<=n&&y+j>=1)
				{
					if(!b[x+j][y+l]&&x+j>=1&&x+j<=n&&y+l>=1&&y+l<=n)
						sum++;
					b[x+j][y+l]=1;
				}
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=-2;j<=2;j++)
			for(int l=-2;l<=2;l++)
				if(x+j<=n&&x+j>=1&&y+j<=n&&y+j>=1)
				{
					if(!b[x+j][y+l]&&x+j>=1&&x+j<=n&&y+l>=1&&y+l<=n)
						sum++;
					b[x+j][y+l]=1;
				}
	}
	printf("%d",n*n-sum);
	return 0;
}
