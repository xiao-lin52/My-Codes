#include<cstdio>
using namespace std;
int n,k,s,b[21][21];
int main()
{
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;i++)
		b[i][i]=1;
	for(int i=1;i<=k;i++)
	{
		int a[21];
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		for(int j=n;j>=1;j--)
			for(int l=n;l>j;l--)
				b[a[j]][a[l]]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!b[i][j])
				s++;
	printf("%d",s);
	return 0;
}
