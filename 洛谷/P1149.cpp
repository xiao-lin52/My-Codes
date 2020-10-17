#include<cstdio>
using namespace std;
int n,ans,match[10]= {6,2,5,5,4,5,6,3,7,6};
int sum(int x)
{
	int s=0;
	if(x==0) s=6;
	for(int a=x; a>0; a/=10)
		s+=match[a%10];
	return s;
}
int main()
{
	scanf("%d",&n);
	n-=4;
	for(int i=0; i<=1000; i++)
		for(int j=0; j<=1000; j++)
			if(sum(i)+sum(j)+sum(i+j)==n)
				ans++;
	printf("%d",ans);
	return 0;
}
