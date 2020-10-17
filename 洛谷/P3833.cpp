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
long long n,m,cnt,dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
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
	rk[cnt]=u;
	id[u]=cnt;
	top[u]=t;
	if(son[u])
		dfs2(son[u],t);
	for(long long i=0;i<edge[u].size();i++)
		if(edge[u][i]!=son[u]&&edge[u][i]!=fa[u])
			dfs2(edge[u][i],edge[u][i]);
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
		return;
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	tree[i].data=tree[i<<1].data+tree[i<<1|1].data;
}
void update(long long i,long long l,long long r,long long k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data+=k*(tree[i].r-tree[i].l+1);
		tree[i].f+=k;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k);
	tree[i].data=tree[i<<1].data+tree[i<<1|1].data;
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
void pathupdate(long long u,long long v,long long k)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		update(1,id[top[u]],id[u],k);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		swap(u,v);
	update(1,id[u],id[v],k);
}
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n-1;i++)
	{
		long long u,v;
		scanf("%lld%lld",&u,&v);
		edge[u+1].push_back(v+1);
		edge[v+1].push_back(u+1);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	scanf("%lld",&m);
	for(long long i=1;i<=m;i++)
	{
		char op;
		long long u,v,k;
		cin>>op;
		if(op=='A')
		{
			scanf("%lld%lld%lld",&u,&v,&k);
			pathupdate(u+1,v+1,k);
		}
		else
		{
			scanf("%lld",&u);
			printf("%lld\n",query(1,id[u+1],id[u+1]+size[u+1]-1));
		}
	}
	return 0;
}
