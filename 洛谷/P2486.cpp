#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct node
{
	int l;
	int r;
	int data;
	int lc;
	int rc;
	int f;
};
node tree[MAXN<<2];
vector<int> edge[MAXN];
int n,m,cnt,w[MAXN],dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
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
			son[u]=size[son[u]]>size[edge[u][i]]? son[u]:edge[u][i];
		}
}
void dfs2(int u,int t)
{
	cnt++;
	rk[cnt]=u;
	id[u]=cnt;
	top[u]=t;
	if(son[u])
		dfs2(son[u],t);
	for(int i=0;i<edge[u].size();i++)
		if(edge[u][i]!=son[u]&&edge[u][i]!=fa[u])
			dfs2(edge[u][i],edge[u][i]);
}
void push_down(int i)
{
	int l=i<<1,r=i<<1|1;
	if(!tree[i].f)
		return;
	tree[l].f=tree[r].f=tree[l].lc=tree[l].rc=tree[r].lc=tree[r].rc=tree[i].f;
	tree[l].data=tree[r].data=1;
	tree[i].f=0;
}
void push_up(int i)
{
	int l=i<<1,r=i<<1|1;
	tree[i].lc=tree[l].lc;
	tree[i].rc=tree[r].rc;
	if(tree[l].rc==tree[r].lc)
		tree[i].data=tree[l].data+tree[r].data-1;
	else
		tree[i].data=tree[l].data+tree[r].data;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].data=1;
		tree[i].lc=tree[i].rc=w[rk[l]];
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	push_up(i);
}
void update(int i,int l,int r,int c)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=1;
		tree[i].lc=tree[i].rc=tree[i].f=c;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,c);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,c);
	push_up(i);
}
node query(int i,int l,int r)
{
	node ans={0,0,0,0,0,0};
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i];
	push_down(i);
	if(tree[i<<1].r>=l)
		ans=query(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
	{
		node tmp=query(i<<1|1,l,r);
		if(ans.rc==tmp.lc)
			ans.data+=tmp.data-1;
		else
			ans.data+=tmp.data;
		if(!ans.lc)
			ans.lc=tmp.lc;
		ans.rc=tmp.rc;
	}
	return ans;
}
void path_update(int u,int v,int c)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		update(1,id[top[u]],id[u],c);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		swap(u,v);
	update(1,id[u],id[v],c);
}
int path_query(int u,int v)
{
	node tmp,ans[2]={{0,0,0,0,0,0},{0,0,0,0,0,0}};
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]])
		{
			tmp=query(1,id[top[u]],id[u]);
			if(ans[0].lc==tmp.rc)
				ans[0].data+=tmp.data-1;
			else
				ans[0].data+=tmp.data;
			ans[0].lc=tmp.lc;
			u=fa[top[u]];
		}
		else
		{
			tmp=query(1,id[top[v]],id[v]);
			if(ans[1].lc==tmp.rc)
				ans[1].data+=tmp.data-1;
			else
				ans[1].data+=tmp.data;
			ans[1].lc=tmp.lc;
			v=fa[top[v]];
		}
	}
	if(dep[u]>dep[v])
	{
		node tmp=query(1,id[v],id[u]);
		if(ans[0].lc==tmp.rc)
			ans[0].data+=tmp.data-1;
		else
			ans[0].data+=tmp.data;
		ans[0].lc=tmp.lc;
		if(ans[0].lc==ans[1].lc)
			ans[0].data+=ans[1].data-1;
		else
			ans[0].data+=ans[1].data;
		return ans[0].data;
	}
	else
	{
		node tmp=query(1,id[u],id[v]);
		if(ans[1].lc==tmp.rc)
			ans[1].data+=tmp.data-1;
		else
			ans[1].data+=tmp.data;
		ans[1].lc=tmp.lc;
		if(ans[1].lc==ans[0].lc)
			ans[1].data+=ans[0].data-1;
		else
			ans[1].data+=ans[0].data;
		return ans[1].data;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		char op;
		int a,b,c;
		cin>>op;
		if(op=='C')
		{
			scanf("%d%d%d",&a,&b,&c);
			path_update(a,b,c);
		}
		else
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",path_query(a,b));
		}
	}
	return 0;
}
