#include<cstdio>
using namespace std;
int n,t,m;
double a;
bool b[2000001]={false};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%d",&a,&t);
		m=m>int(a*t)? m:int(a*t);
		for(int j=1;j<=t;j++)
			b[int(a*j)]=!b[int(a*j)];
	}
	for(int i=1;i<=m;i++)
		if(b[i])
		{
			printf("%d",i);
			break;
		}
	return 0;
}
