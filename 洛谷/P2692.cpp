#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,h,i;
int main()
{
	scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
	if(h==0)
		if(50+a+b+c+d+e+f+g>=i)
			printf("AKIOI");
		else
			printf("AFO");
	else
		if(50+a+b+c+d+e+f+g>=i+5)
			printf("AKIOI");
		else
			printf("AFO");
	return 0;
}
