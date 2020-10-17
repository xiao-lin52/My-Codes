#include<cstdio>
using namespace std;
int n,m,l,r,a[1000001]={1,1},s[1000001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;2*i<=m;i++)
		if(!a[i])
			for(int j=2;j*i<=m;j++)
				a[i*j]=1;
	for(int i=1;i<=m;i++)
		if(!a[i])
			s[i]=s[i-1]+1;
		else
			s[i]=s[i-1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		if(l<1||r>m)
		{
			printf("Crossing the line\n");
			continue;
		}
		printf("%d\n",s[r]-s[l-1]);
	}
	return 0;
}
