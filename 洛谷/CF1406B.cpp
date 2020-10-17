#include<bits/stdc++.h>
#define N 100010
#define ll long long
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll t,n,k1,k2,x1,x2,ans,b[N],c[N];
int main()
{
	t=read();
	while(t--)
	{
		k1=0;
		k2=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
			ll a=read();
			if(a>=0)
				b[++k1]=a;
			else
				c[++k2]=a;
		}
		sort(b+1,b+1+k1);
		sort(c+1,c+1+k2);
		x1=max(0,5-k1);
		x2=min(5,k2);
		for(int i=x1;i<=x2;i++)
		{
			ll sum=1;
			if(i%2)
			{
				for(int j=1;j<=i&&j<=k2;j++)
					sum*=c[k2-j+1];
				for(int j=1;j<=5-i&&j<=k1;j++)
					sum*=b[j];
			}
			else
			{
				for(int j=1;j<=i&&j<=k2;j++)
					sum*=c[j];
				for(int j=1;j<=5-i&&j<=k1;j++)
					sum*=b[k1-j+1];
			}
			if(i==x1)
				ans=sum;
			else
				ans=max(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
