#include<cstdio>
using namespace std;
int x,y,n,x1,x2,y1,y2,ans,map[500][500];
int main()
{
	scanf("%d%d%d",&x,&y,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int j=x1;j<=x2;j++)
			for(int k=y1;k<=y2;k++)
				if(!map[j][k])
				{
					map[j][k]=1;
					ans++;
				}
	}
	printf("%d",ans);
	return 0;
}
