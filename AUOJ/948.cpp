#include<bits/stdc++.h>
#define ll int
#define mod 998244353
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll n,m,tp,flag=1,ans=1,f[600010],vis[300010];
inline ll find(ll x)
{
	return f[x]==x? f[x]:f[x]=find(f[x]);
}
int main()
{
	n=read();
	m=read();
	tp=read();
	for(int i=1;i<=2*n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		ll x=read(),y=read(),w=read(),t1,t2;
		t1=find(x);
		t2=find(y);
		if((w==0&&t1==t2)||(w==1&&(t1==t2+n||t1+n==t2)))
			flag=0;
		else
		{
			if(w)
			{
				f[find(x)]=find(y);
				f[find(x+n)]=find(y+n);
			}
			else
			{
				f[find(x)]=find(y+n);
				f[find(x+n)]=find(y);
			}
		}
	}
	if(tp==1)
		if(flag)
			printf("YES");
		else
			printf("NO");
	else
		if(flag)
		{
			for(int i=1;i<=n;i++)
			{
				ll tmp=(find(i)-1)%n+1;
				if(!vis[tmp])
					ans=ans*2%mod;
				vis[tmp]=1;
			}
			printf("%d",ans);
		}
		else
			printf("0");
	return 0;
}
