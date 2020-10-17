#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int a11,a21,b11,b21,s,s21[100000][2];
char x;
int main()
{
	scanf("%c",&x);
	while(x!='E')
	{
		if(x=='W')
		{
			a11++;
			a21++;
		}
		if(x=='L')
		{
			b11++;
			b21++;
		}
		if(abs(a11-b11)>=2&&(a11>=11||b11>=11))
		{
			printf("%d:%d\n",a11,b11);
			a11=b11=0;
		}
		if(abs(a21-b21)>=2&&(a21>=21||b21>=21))
		{
			s++;
			s21[s][0]=a21;
			s21[s][1]=b21;
			a21=b21=0;
		}
		scanf("%c",&x);
	}
	s++;
	s21[s][0]=a21;
	s21[s][1]=b21;
	printf("%d:%d\n\n",a11,b11);
	for(int i=1;i<=s;i++)
		printf("%d:%d\n",s21[i][0],s21[i][1]);
	return 0;
}
