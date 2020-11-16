#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,mod=998244353;
ll n,m,q,len,num,a[N],belong[N],l[1010],r[1010],tag[1010];
vector<ll> op[N];
inline void push_down(int x)
{
	if(tag[x]==1)
		return;
	for(int i=l[x];i<=r[x];i++)
		a[i]=a[i]*tag[x]%mod;
	tag[x]=1;
}
void update(int opr,int x,int k)
{
	if(opr==1)
	{
		push_down(belong[x]);
		a[x]=(a[x]+k)%mod;
	}
	else
		for(int i=1;i<=num;i++)
			tag[i]=tag[i]*k%mod;
}
void dfs(ll x)
{
	if(op[x][0]==1)
		update(1,op[x][1],op[x][2]);
	if(op[x][0]==2)
		update(2,0,op[x][1]);
	if(op[x][0]==3)
	{
		int s=op[x].size();
		for(int i=2;i<s;i++)
			dfs(op[x][i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%lld",&n);
	len=sqrt(n);
	num=(n-1)/len+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		belong[i]=(i-1)/len+1;
	}
	for(int i=1;i<=num;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=min(n,i*len);
		tag[i]=1;
	}
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		ll t,p,v,c,g;
		scanf("%lld",&t);
		op[i].push_back(t);
		if(t==1)
		{
			scanf("%lld%lld",&p,&v);
			op[i].push_back(p);
			op[i].push_back(v);
		}
		if(t==2)
		{
			scanf("%lld",&v);
			op[i].push_back(v);
		}
		if(t==3)
		{
			scanf("%lld",&c);
			op[i].push_back(c);
			for(int j=1;j<=c;j++)
			{
				scanf("%lld",&g);
				op[i].push_back(g);
			}
		}
	}
	scanf("%lld",&q);
	for(int i=1;i<=q;i++)
	{
		ll f;
		scanf("%lld",&f);
		dfs(f);
	}
	for(int i=1;i<=num;i++)
		push_down(i);
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
