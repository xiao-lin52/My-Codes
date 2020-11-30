#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct SegTree
{
	int ls;
	int rs;
	int data;
};
struct Query
{
	int x,y,c,id;
};
Query q[N];
SegTree tree[N*21];
int n,m,tot,cnt,log2n,val[N],rt[N],dep[N],fa[N][20];
vector<int> edge[N];
void update(int i,int &j,int l,int r,int x)
{
	j=++tot;
	tree[j]=tree[i];
	tree[j].data++;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(x<=mid)
		update(tree[i].ls,tree[j].ls,l,mid,x);
	else
		update(tree[i].rs,tree[j].rs,mid+1,r,x);
}
int query(int i,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(l==r)
		return 0;
	if(x<=mid)
		return query(tree[i].ls,l,mid,x);
	else
		return tree[tree[i].ls].data+query(tree[i].rs,mid+1,r,x);
}
void dfs(int u)
{
	rt[u]=rt[fa[u][0]];
	dep[u]=dep[fa[u][0]]+1;
	for(int i=1;(1<<i)<=dep[u];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	if(val[u])
		update(rt[fa[u][0]],rt[u],1,m,val[u]);
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa[u][0])
			dfs(v);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	int depu=dep[u],depv=dep[v];
	for(int i=0;(1<<i)<=depu-depv;i++)
		if((depu-depv)&(1<<i))
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=log2n;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
		{
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
int main()
{
	scanf("%d",&n);
	log2n=log(n)/log(2)+0.5;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&fa[i][0]);
		edge[fa[i][0]].push_back(i);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			cnt++;
			scanf("%d%d%d",&q[cnt].x,&q[cnt].y,&q[cnt].c);
			q[cnt].id=i;
		}
		else
		{
			int t;
			scanf("%d",&t);
			val[t]=i;
		}
	}
	for(int i=1;i<=n;i++)
		if(!fa[i][0])
		{
			dfs(i);
			break;
		}
	for(int i=1;i<=cnt;i++)
	{
		int u=q[i].x,v=q[i].y,t=lca(u,v),sum=dep[u]+dep[v]-dep[t]-dep[fa[t][0]];
		int q1=query(rt[u],1,m,q[i].id-q[i].c),q2=query(rt[v],1,m,q[i].id-q[i].c);
		int q3=(query(rt[t],1,m,q[i].id-q[i].c)),q4=query(rt[fa[t][0]],1,m,q[i].id-q[i].c);
		printf("%d %d\n",sum,q1+q2-q3-q4);
	}
	return 0;
}