#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(c==0)
		if(a==b)
			printf("YES");
		else
			printf("NO");
	else
		if((b-a)%c==0&&(b-a)/c>=0)
			printf("YES");
		else
			printf("NO");
	return 0;
}
