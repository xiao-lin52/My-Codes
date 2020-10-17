#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct node
{
	int l;
	int r;
	int data;
	int f;
};
node tree[MAXN<<2];
vector<int> edge[MAXN];
int n,m,r,p,cnt,w[MAXN];
int dep[MAXN],fa[MAXN],son[MAXN],size[MAXN],top[MAXN],rk[MAXN],id[MAXN];

void dfs1(int u,int father)
{
	dep[u]=dep[father]+1;
	fa[u]=father;
	size[u]=1;
	for(int i=0;i<edge[u].size();i++)
		if(edge[u][i]!=father)
		{
			dfs1(edge[u][i],u);
			size[u]+=size[edge[u][i]];
			son[u]=size[edge[u][i]]>size[son[u]]? edge[u][i]:son[u];
		}
}

void dfs2(int u,int father,int t)
{
	cnt++;
	top[u]=t;
	rk[cnt]=u;
	id[u]=cnt;
	if(son[u])
		dfs2(son[u],u,t);
	for(int i=0;i<edge[u].size();i++)
		if(edge[u][i]!=son[u]&&edge[u][i]!=father)
			dfs2(edge[u][i],u,edge[u][i]);
}

void push_down(int i)
{
	int l=i<<1,r=i<<1|1;
	if(!tree[i].f)
		return;
	tree[l].data=(tree[l].data+tree[i].f*(tree[l].r-tree[l].l+1)%p)%p;
	tree[r].data=(tree[r].data+tree[i].f*(tree[r].r-tree[r].l+1)%p)%p;
	tree[l].f=(tree[l].f+tree[i].f)%p;
	tree[r].f=(tree[r].f+tree[i].f)%p;
	tree[i].f=0;
}

void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].data=w[rk[l]]%p;
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	tree[i].data=(tree[i<<1].data+tree[i<<1|1].data)%p;
}

void update(int i,int l,int r,int k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=(tree[i].data+(tree[i].r-tree[i].l+1)*k%p)%p;
		tree[i].f=(tree[i].f+k)%p;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k);
	tree[i].data=(tree[i<<1].data+tree[i<<1|1].data)%p;
}

int query(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data%p;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans=(ans+query(i<<1,l,r))%p;
	if(tree[i<<1|1].l<=r)
		ans=(ans+query(i<<1|1,l,r))%p;
	return ans%p;
}

int lca_query(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v])
		if(dep[top[u]]>=dep[top[v]])
		{
			ans=(ans+query(1,id[top[u]],id[u]))%p;
			u=fa[top[u]];
		}
		else
		{
			ans=(ans+query(1,id[top[v]],id[v]))%p;
			v=fa[top[v]];
		}
	if(dep[u]>=dep[v])
		ans=(ans+query(1,id[v],id[u]))%p;
	else
		ans=(ans+query(1,id[u],id[v]))%p;
	return ans;
}

void lca_update(int u,int v,int k)
{
	while(top[u]!=top[v])
		if(dep[top[u]]>=dep[top[v]])
		{
			update(1,id[top[u]],id[u],k);
			u=fa[top[u]];
		}
		else
		{
			update(1,id[top[v]],id[v],k);
			v=fa[top[v]];
		}
	if(dep[u]>=dep[v])
		update(1,id[v],id[u],k);
	else
		update(1,id[u],id[v],k);
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(r,0);
	dfs2(r,0,r);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x,y,z;
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				scanf("%d%d%d",&x,&y,&z);
				lca_update(x,y,z);
				break;
			case 2:
				scanf("%d%d",&x,&y);
				printf("%d\n",lca_query(x,y));
				break;
			case 3:
				scanf("%d%d",&x,&z);
				update(1,id[x],id[x]+size[x]-1,z);
				break;
			case 4:
				scanf("%d",&x);
				printf("%d\n",query(1,id[x],id[x]+size[x]-1));
				break;
		}
	}
	return 0;
}
