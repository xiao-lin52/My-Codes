#include<cstdio>
using namespace std;
int h1,h2,m1,m2,s1,s2,n;
long long ans;//long long不能忘 
int main()
{
	scanf("%d:%d:%d%d:%d:%d%d",&h1,&m1,&s1,&h2,&m2,&s2,&n);//用scanf的神奇功能，凡是除格式控制符以外的所有字符必须真实输入。 
	while(!(h1==h2&&m1==m2&&s1==s2))
	{
		s1++;
		if(s1==60)//如果秒数满了就清零，分钟数加一 
		{
			m1++;
			s1=0;
		}
		if(m1==60)//如果分钟数满了也清零，小时数加一 
		{
			h1++;
			m1=s1=0;
		}
		ans+=n;
	}
	printf("%lld",ans);//输出不解释 
	return 0;//（华丽结束） 
}
