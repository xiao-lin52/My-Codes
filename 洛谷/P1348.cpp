#include<cstdio>
using namespace std;
long long n,m,s;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=n;i<=m;i++)
		if(i%2!=0||i%4==0)
			s++;
	printf("%lld",s);
	return 0;
}
