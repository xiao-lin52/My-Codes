#include<cstdio>
using namespace std;
int m,d,ans,day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	scanf("%d-%d",&m,&d);
	if(m<1||m>12)
	{
		ans++;
		if(m/10==1)
			m=12;
		if(m%10!=0&&m%10!=2&&m/10!=1)
			m%=10;
		else
			m=m%10+10;
	}
	if(d<1||d>day[m])
		ans++;
	printf("%d",ans);
	return 0;
}
