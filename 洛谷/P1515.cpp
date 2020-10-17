#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,n,ans,hotel[34]= {0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
void dfs(int x)
{
	int c;
	for(int i=x+1; i<35; i++)
	{
		c=hotel[i]-hotel[x];
		if(c>=a&&c<=b)
			if(i==13+n)
				ans++;
			else
				dfs(i);
	}
}
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&hotel[i+13]);
	sort(hotel,hotel+14+n);
	dfs(0);
	printf("%d",ans);
	return 0;
}
