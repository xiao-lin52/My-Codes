#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,mod=1e9+7;
ll n,len,ans,nxt[N],num[N];
char a[N];
int main()
{
	scanf("%lld",&n);
	while(n--)
	{
		ans=1;
		memset(a,0,sizeof(a));
		memset(nxt,0,sizeof(nxt));
		memset(num,0,sizeof(num));
		scanf("%s",a+1);
		len=strlen(a+1);
		num[1]=1;
		for(int i=2,j=0;i<=len;i++)
		{
			while(a[i]!=a[j+1]&&j)
				j=nxt[j];
			if(a[i]==a[j+1])
				j++;
			nxt[i]=j;
			num[i]=(num[j]+1)%mod;
		}
		for(int i=2,j=2;i<=len;i++)
		{
			ll s=0;
			while(a[i]!=a[j+1]&&j)
				j=nxt[j];
			if(a[i]==a[j+1])
				j++;
			while(j>i/2)
				j=nxt[j];
			ans=ans*(num[j]+1)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}