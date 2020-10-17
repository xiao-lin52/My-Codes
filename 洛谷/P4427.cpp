#include<bits/stdc++.h>
#define MAXN 300001
#define mod 998244353
using namespace std;
struct node
{
	long long l;
	long long r;
	long long data[51];
};
node tree[MAXN<<2];
vector<long long> edge[MAXN];
long long n,m,cnt,dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
long long ksm(long long b,long long k)
{
	long long ans=1;
	while(k)
	{
		if(k&1)
			ans=ans*b%mod;
		k>>=1;
		b=b*b%mod;
	}
	return ans%mod;
}
void dfs1(long long u,long long father)
{
	dep[u]=dep[father]+1;
	fa[u]=father;
	size[u]=1;
	for(long long i=0;i<edge[u].size();i++)
		if(edge[u][i]!=father)
		{
			dfs1(edge[u][i],u);
			size[u]+=size[edge[u][i]];
			son[u]=size[son[u]]>size[edge[u][i]]? son[u]:edge[u][i];
		}
}
void dfs2(long long u,long long father,long long t)
{
	cnt++;
	rk[cnt]=u;
	id[u]=cnt;
	top[u]=t;
	if(son[u])
		dfs2(son[u],u,t);
	for(long long i=0;i<edge[u].size();i++)
		if(edge[u][i]!=father&&edge[u][i]!=son[u])
			dfs2(edge[u][i],u,edge[u][i]);
}
void build(long long i,long long l,long long r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		for(long long k=1;k<=50;k++)
			tree[i].data[k]=ksm(dep[rk[l]],k)%mod;
		return;
	}
	long long mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	for(long long k=1;k<=50;k++)
		tree[i].data[k]=(tree[i<<1].data[k]+tree[i<<1|1].data[k])%mod;
}
long long query(long long i,long long l,long long r,long long k)
{
	long long ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data[k]%mod;
	if(tree[i<<1].r>=l)
		ans=(ans+query(i<<1,l,r,k))%mod;
	if(tree[i<<1|1].l<=r)
		ans=(ans+query(i<<1|1,l,r,k))%mod;
	return ans%mod;
}
long long lca_query(long long u,long long v,long long k)
{
	long long ans=0;
	while(top[u]!=top[v])
		if(dep[top[u]]>=dep[top[v]])
		{
			ans=(ans+query(1,id[top[u]],id[u],k))%mod;
			u=fa[top[u]];
		}
		else
		{
			ans=(ans+query(1,id[top[v]],id[v],k))%mod;
			v=fa[top[v]];
		}
	if(dep[u]>=dep[v])
		ans=(ans+query(1,id[v],id[u],k))%mod;
	else
		ans=(ans+query(1,id[u],id[v],k))%mod;
	return ans%mod;
}
int main()
{
	n=read();
	for(long long i=1;i<=n-1;i++)
	{
		long long u,v;
		u=read();
		v=read();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dep[0]=-1;
	dfs1(1,0);
	dfs2(1,0,1);
	build(1,1,n);
	m=read();
	for(long long i=1;i<=m;i++)
	{
		long long u,v,k;
		u=read();
		v=read();
		k=read();
		printf("%lld\n",lca_query(u,v,k)%mod);
	}
	return 0;
}
