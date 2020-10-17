#include<cstdio>
using namespace std;
int n,m,a,judge[10000001]={1,1};
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i*2<=n;i++)
		if(!judge[i])
			for(int j=2;i*j<=n;j++)
				judge[i*j]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a);
		if(!judge[a])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
