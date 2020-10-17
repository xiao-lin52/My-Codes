#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k,t,ans;
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=k;i++)
	{
		int x,y,s=0;
		scanf("%d%d",&x,&y);
		for(int j=max(x-t,1);j<=min(n,x+t);j++)
			for(int l=max(y-t,1);l<=min(m,y+t);l++)
				if(sqrt((x-j)*(x-j)+(y-l)*(y-l))<=t)
					s++;
		ans=max(ans,s);
	}
	printf("%d",ans);
	return 0;
}