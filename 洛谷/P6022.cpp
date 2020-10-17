#include<cstdio>
#include<cstring>
using namespace std;
int n,m,flag,a[6],s[6],b[6];
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	while(n)
	{
		ans+=n;
		for(int i=1;i<=m;i++)
			s[i]+=n;
		if(!memcmp(b,s,sizeof(s)))
		{
			if(flag)
			{
				printf("Inf");
				return 0;
			}
			else
				flag++;
		}
		memcpy(b,s,sizeof(s));
		n=0;
		for(int i=1;i<=m;i++)
		{
			n+=s[i]/a[i];
			s[i]%=a[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
