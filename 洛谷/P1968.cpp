#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[101];
double m[101][2];
void dfs(int x,int p)//0代表美元，1代表马克 
{
	if(p==0)
	{
		if(m[x-1][0]>m[x][0])
		{
			m[x][0]=m[x-1][0];
			if(x!=n)
				dfs(x+1,0);
		}
		if(m[x-1][0]/100*a[x]>m[x][1]&&x!=n)
		{
			m[x][1]=m[x-1][0]/100*a[x];
			if(x!=n)
				dfs(x+1,1);
		}
	}
	else
	{
		if(m[x-1][1]>m[x][1]&&x!=n)
		{
			m[x][1]=m[x-1][1];
			if(x!=n)
				dfs(x+1,1);
		}
		if(m[x-1][1]/a[x]*100>m[x][0])
		{
			m[x][0]=m[x-1][1]/a[x]*100;
			if(x!=n)
				dfs(x+1,0);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	m[0][0]=100;
	dfs(1,0);
	printf("%.2lf",m[n][0]);
	return 0;
}