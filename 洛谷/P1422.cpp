#include<cstdio>
using namespace std;
double n,sum;
int main()
{
	scanf("%lf",&n);
	if(n>400)
		sum+=(n-400)*0.5663,n=400;
	if(n>150)
		sum+=(n-150)*0.4663,n=150;
	if(n>0)
		sum+=n*0.4463;
	printf("%.1lf",sum); 
	return 0;
}
