#include<cstdio>
using namespace std;
int h1,h2,m1,m2,s1,s2,n;
long long ans;//long long������ 
int main()
{
	scanf("%d:%d:%d%d:%d:%d%d",&h1,&m1,&s1,&h2,&m2,&s2,&n);//��scanf�����湦�ܣ����ǳ���ʽ���Ʒ�����������ַ�������ʵ���롣 
	while(!(h1==h2&&m1==m2&&s1==s2))
	{
		s1++;
		if(s1==60)//����������˾����㣬��������һ 
		{
			m1++;
			s1=0;
		}
		if(m1==60)//�������������Ҳ���㣬Сʱ����һ 
		{
			h1++;
			m1=s1=0;
		}
		ans+=n;
	}
	printf("%lld",ans);//��������� 
	return 0;//������������ 
}
