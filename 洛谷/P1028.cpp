#include<cstdio>
using namespace std;
int n,f[1001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i/2;j++)
			f[i]+=f[j];
	printf("%d",f[n]);
	return 0;
}
