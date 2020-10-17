#include<cstdio>
using namespace std;
int date1,date2,test,s,d[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
	scanf("%d%d",&date1,&date2);
	for(int i=1;i<=12;i++)
		for(int j=1;j<=d[i];j++)
		{
			test=j+i*100+(i%10*10+i/10)*10000+(j%10*10+j/10)*1000000;
			if(test>=date1&&test<=date2)
				s++;
		}
	printf("%d",s);
	return 0;
}