#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct node
{
	long long l;
	long long r;
	long long data;
	long long f;
};
node tree[MAXN<<2];
vector<long long> edge[MAXN];
long long n,m,cnt,w[MAXN],dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
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
void dfs2(long long u,long long t)
{
	cnt++;
	top[u]=t;
	rk[cnt]=u;
	id[u]=cnt;
	if(son[u])
		dfs2(son[u],t);
	for(long long i=0;i<edge[u].size();i++)
		if(edge[u][i]!=fa[u]&&edge[u][i]!=son[u])
			dfs2(edge[u][i],edge[u][i]);
}
void push_up(long long i)
{
	long long l=i<<1,r=i<<1|1;
	tree[i].data=tree[l].data+tree[r].data;
}
void push_down(long long i)
{
	long long l=i<<1,r=i<<1|1;
	if(!tree[i].f)
		return;
	tree[l].f+=tree[i].f;
	tree[r].f+=tree[i].f;
	tree[l].data+=tree[i].f*(tree[l].r-tree[l].l+1);
	tree[r].data+=tree[i].f*(tree[r].r-tree[r].l+1);
	tree[i].f=0;
}
void build(long long i,long long l,long long r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].data=w[rk[l]];
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	push_up(i);
}
void update(long long i,long long l,long long r,long long k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].f+=k;
		tree[i].data+=k*(tree[i].r-tree[i].l+1);
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k);
	push_up(i);
}
long long query(long long i,long long l,long long r)
{
	long long ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans+=query(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		ans+=query(i<<1|1,l,r);
	return ans;
}
long long path_query(long long u,long long v)
{
	long long ans=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans+=query(1,id[top[u]],id[u]);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		swap(u,v);
	return ans+query(1,id[u],id[v]);
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	for(long long i=1;i<=n-1;i++)
	{
		long long u,v;
		scanf("%lld%lld",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(long long i=1;i<=m;i++)
	{
		long long op,x,a;
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld%lld",&x,&a);
			update(1,id[x],id[x],a);
		}
		if(op==2)
		{
			scanf("%lld%lld",&x,&a);
			update(1,id[x],id[x]+size[x]-1,a);
		}
		if(op==3)
		{
			scanf("%lld",&x);
			printf("%lld\n",path_query(x,1));
		}
	}
	return 0;
}
