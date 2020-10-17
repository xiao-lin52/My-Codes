#include<bits/stdc++.h>
#define MAXN 100005
#define inf 1e9
using namespace std;
struct node
{
	long long l;
	long long r;
	long long data;
	long long f1=-1;
	long long f2;
};
node tree[MAXN<<2];
vector<int> edge[MAXN];
long long n,cnt,w[MAXN],u[MAXN],v[MAXN],c[MAXN];
long long dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
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
void push_down(long long i)
{
	long long l=i<<1,r=i<<1|1;
	if(tree[i].f1==-1&&!tree[i].f2)
		return;
	if(tree[i].f1!=-1)
	{
		tree[l].f1=tree[i].f1;
		tree[r].f1=tree[i].f1;
		tree[l].f2=0;
		tree[r].f2=0;
		tree[l].data=tree[i].f1;
		tree[r].data=tree[i].f1;
	}
	if(tree[i].f2)
	{
		tree[l].f2+=tree[i].f2;
		tree[r].f2+=tree[i].f2;
		tree[l].data+=tree[i].f2;
		tree[r].data+=tree[i].f2;
	}
	tree[i].f1=-1;
	tree[i].f2=0;
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
	tree[i].data=max(tree[i<<1].data,tree[i<<1|1].data);
}
void update(long long i,long long l,long long r,long long k,long long op)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		if(op==1)
		{
			tree[i].data=k;
			tree[i].f1=k;
			tree[i].f2=0;
		}
		else
		{
			tree[i].data+=k;
			tree[i].f2+=k;
		}
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k,op);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k,op);
	tree[i].data=max(tree[i<<1].data,tree[i<<1|1].data);
}
long long query(long long i,long long l,long long r)
{
	long long ans=-inf;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans=max(ans,query(i<<1,l,r));
	if(tree[i<<1|1].l<=r)
		ans=max(ans,query(i<<1|1,l,r));
	return ans;
}
void lca_update(long long u,long long v,long long k,long long op)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		update(1,id[top[u]],id[u],k,op);
		u=fa[top[u]];
	}
	if(u==v)
		return;
	if(dep[u]<dep[v])
		swap(u,v);
	update(1,id[son[v]],id[u],k,op);
}
long long lca_query(long long u,long long v)
{
	long long ans=-inf;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans=max(ans,query(1,id[top[u]],id[u]));
		u=fa[top[u]];
	}
	if(u==v)
		return ans;
	if(dep[u]<dep[v])
		swap(u,v);
	return max(ans,query(1,id[son[v]],id[u]));
}
int main()
{
//	freopen("P4315_1.in","r",stdin);
//	freopen("fuck.you","w",stdout);
	cin>>n;
	for(long long i=1;i<=n-1;i++)
	{
		cin>>u[i]>>v[i]>>c[i];
		edge[u[i]].push_back(v[i]);
		edge[v[i]].push_back(u[i]);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	build(1,1,n);
	for(long long i=1;i<=n-1;i++)
	{
		if(dep[u[i]]<dep[v[i]])
			swap(u[i],v[i]);
		update(1,id[u[i]],id[u[i]],c[i],1);
	}
	while(1)
	{
		long long a,b,c;
		string op;
		cin>>op;
		if(op=="Stop")
			break;
		if(op=="Change")
		{
			cin>>a>>b;
			update(1,id[u[a]],id[u[a]],b,1);
		}
		if(op=="Cover")
		{
			cin>>a>>b>>c;
			lca_update(a,b,c,1);
		}
		if(op=="Add")
		{
			cin>>a>>b>>c;
			lca_update(a,b,c,2);
		}
		if(op=="Max")
		{
			cin>>a>>b;
			printf("%lld\n",lca_query(a,b));
		}
	}
	return 0;
}
