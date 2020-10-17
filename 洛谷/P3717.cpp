#include<cstdio>
#include<cmath>
using namespace std;
int n,m,r,s,b[101][101];
int main()
{
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=-r;j<=r;j++)
			for(int l=-r;l<=r;l++)
				if(x+j>=1&&x+j<=n&&y+l>=1&&y+l<=n)
					if(sqrt(j*j+l*l)<=r)
						b[x+j][y+l]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(b[i][j])
				s++;
	printf("%d",s);
	return 0;
}
