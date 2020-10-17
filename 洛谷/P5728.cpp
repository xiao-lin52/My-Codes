#include<cstdio>
#include<cmath>
using namespace std;
struct score
{
	int c;
	int m;
	int e;
	int t;
};
score a[1001];
int n,s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].c,&a[i].m,&a[i].e);
		a[i].t=a[i].c+a[i].m+a[i].e;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			if(abs(a[i].c-a[j].c)>5)
				continue;
			if(abs(a[i].m-a[j].m)>5)
				continue;
			if(abs(a[i].e-a[j].e)>5)
				continue;
			if(abs(a[i].t-a[j].t)>10)
				continue;
			s++;
		}
	printf("%d",s);
	return 0;
}
