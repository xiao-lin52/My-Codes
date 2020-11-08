#include<cstdio>
using namespace std;
int h1,m1,h2,m2,s,t,ans;
int main()
{
	scanf("%d:%d%d:%d",&h1,&m1,&h2,&m2);
	s=h1*60+m1;
	t=h2*60+m2;
	if(s<t)
		s+=1440;
	ans=s-t;
	printf("%02d:%02d",ans/60,ans%60);
	return 0;
}
