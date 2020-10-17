#include<cstdio>
using namespace std;
int r,b,c,d,e,m,score;
int main()
{
	scanf("%d%d%d%d%d",&r,&b,&c,&d,&e);
	score=r*c+b*d;
	m=r>b? b:r;
	if(e+e-c-d>0)
		score+=(e+e-c-d)*m;
	printf("%d",score);
	return 0;
}
