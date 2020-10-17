#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll t,n,ans,a[N],p[N];
int main()
{
	t=read();
	while(t--)
	{
		ans=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			p[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
			if(p[i]!=i)
			{
				ll t=a[i];
				swap(a[i],a[p[i]]);
				swap(p[t],p[i]);
				ans++;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
