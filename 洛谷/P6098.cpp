#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct node
{
	long long l;
	long long r;
	long long data;
};
node tree[MAXN<<2];
vector<long long> edge[MAXN];
long long n,m,cnt,e[MAXN],dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],top[MAXN],rk[MAXN],id[MAXN];
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
	top[u]=t;
	rk[cnt]=u;
	id[u]=cnt;
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
		tree[i].data=e[rk[l]];
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	tree[i].data=tree[i<<1].data^tree[i<<1|1].data;
}
void update(long long i,long long l,long long r,long long k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=k;
		return;
	}
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k);
	tree[i].data=tree[i<<1].data^tree[i<<1|1].data;
}
long long query(long long i,long long l,long long r)
{
	long long ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	if(tree[i<<1].r>=l)
		ans^=query(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		ans^=query(i<<1|1,l,r);
	return ans;
}
long long lca_query(long long u,long long v)
{
	long long ans=0;
	while(top[u]!=top[v])
		if(dep[top[u]]>=dep[top[v]])
		{
			ans^=query(1,id[top[u]],id[u]);
			u=fa[top[u]];
		}
		else
		{
			ans^=query(1,id[top[v]],id[v]);
			v=fa[top[v]];
		}
	if(dep[u]>=dep[v])
		return ans^=query(1,id[v],id[u]);
	else
		return ans^=query(1,id[u],id[v]);
//	if(u==v)
//		return ans;
}
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&e[i]);
	for(long long i=1;i<=n-1;i++)
	{
		long long u,v;
		scanf("%lld%lld",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	build(1,1,n);
	for(long long i=1;i<=m;i++)
	{
		long long op,a,b;
		scanf("%lld%lld%lld",&op,&a,&b);
		if(op==1)
			update(1,id[a],id[a],b);
		else
			printf("%lld\n",lca_query(a,b));
	}
	return 0;
}
