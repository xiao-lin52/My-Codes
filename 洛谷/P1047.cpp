#include<cstdio>
using namespace std;
int l,n,ans,b[10010];
int main()
{
	scanf("%d%d",&l,&n);
	for(int i=1;i<=n;i++)
	{
		int left,right;
		scanf("%d%d",&left,&right);
		for(int j=left;j<=right;j++)
			b[j]=1;
	}
	for(int i=0;i<=l;i++)
		if(!b[i])
			ans++;
	printf("%d",ans);
	return 0;
}
