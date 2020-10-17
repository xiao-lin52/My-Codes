#include<cstdio>
using namespace std;
int i,n,s;
int main()
{
	scanf("%d",&n);
	for(i=1;(1+i)*i/2<n;i++)
		s+=i*i;
	s+=i*(n-(i-1)*i/2);
	printf("%d",s);
	return 0;
}
