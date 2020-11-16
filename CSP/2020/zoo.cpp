#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e6+10;
int cnt(ll x)
{
	int sum=0;
	for(;x;x-=(x&(-x)))
		sum++;
	return sum;
}
ll n,m,c,k,mk,ans,a[N],p[N],q[N];
bitset<100000010> lt;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%llu%llu%llu%llu",&n,&m,&c,&k);
	ans=(1ull<<(k-1))-1+(1ull<<(k-1));
	for(int i=1;i<=n;i++)
	{
		scanf("%llu",&a[i]);
		mk|=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%llu%llu",&p[i],&q[i]);
		if(mk&(1<<p[i]))
			lt[q[i]]=1;
	}
	for(int i=1;i<=m;i++)
		if((!lt[q[i]])&&(ans&(1<<p[i])))
			ans^=(1<<p[i]);
	printf("%llu",(1ull<<cnt(ans))-n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
