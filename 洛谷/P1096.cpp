#include<cstdio>
using namespace std;
int n,w=1,opt[2000];
void plus()
{
	int jw=0;
	for(int i=1;i<=w;i++)
	{
		opt[i]=opt[i]*2+jw;
		jw=opt[i]/10;
		opt[i]%=10;
	}
	if(jw)
		opt[++w]=jw;
	jw=0;
	opt[1]+=2;
	for(int i=1;i<=w;i++)
	{
		opt[i]+=jw;
		jw=opt[i]/10;
		opt[i]%=10;
	}
	if(jw)
		opt[++w]=jw;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		plus();
	for(int i=w;i>=1;i--)
		printf("%d",opt[i]);
	return 0;
}
