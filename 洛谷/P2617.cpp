#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e5+10;
struct Query
{
	int op,x,y,k;
};
Query q[N];
int n,m,tot,qwq,a[N],c[10*N],rt[N],st[N],ed[N],ls[N*300],rs[N*300],dat[N*300];
void Segupdate(int &i,int l,int r,int x,int k)
{
	if(!i)
		i=++tot;
	dat[i]+=k;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(x<=mid)
		Segupdate(ls[i],l,mid,x,k);
	else
		Segupdate(rs[i],mid+1,r,x,k);
}
int getkth(int l,int r,int k)
{
	if(l==r)
		return l;
	int s1=0,s2=0;
	for(int i=1;i<=st[0];i++)
		s1+=dat[ls[st[i]]];
	for(int i=1;i<=ed[0];i++)
		s2+=dat[ls[ed[i]]];
	int mid=(l+r)>>1;
	if(s2-s1>=k)
	{
		for(int i=1;i<=st[0];i++)
			st[i]=ls[st[i]];
		for(int i=1;i<=ed[0];i++)
			ed[i]=ls[ed[i]];
		return getkth(l,mid,k);
	}
	else
	{
		for(int i=1;i<=st[0];i++)
			st[i]=rs[st[i]];
		for(int i=1;i<=ed[0];i++)
			ed[i]=rs[ed[i]];
		return getkth(mid+1,r,k-(s2-s1));
	}
}
void update(int x,int p,int k)
{
	for(;x<=n;x+=lowbit(x))
		Segupdate(rt[x],1,qwq,p,k);
}
int query(int l,int r,int k)
{
	st[0]=ed[0]=0;
	for(;l>=1;l-=lowbit(l))
		st[++st[0]]=rt[l];
	for(;r>=1;r-=lowbit(r))
		ed[++ed[0]]=rt[r];
	return getkth(1,qwq,k);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[++qwq]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		char op[2];
		scanf("%s%d%d",op,&q[i].x,&q[i].y);
		if(op[0]=='Q')
		{
			q[i].op=1;
			scanf("%d",&q[i].k);
		}
		else
		{
			q[i].op=2;
			c[++qwq]=q[i].y;
		}
	}
	sort(c+1,c+1+qwq);
	qwq=unique(c+1,c+1+qwq)-c-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(c+1,c+1+qwq,a[i])-c;
		update(i,a[i],1);
	}
	for(int i=1;i<=m;i++)
		if(q[i].op==2)
			q[i].y=lower_bound(c+1,c+1+qwq,q[i].y)-c;
	for(int i=1;i<=m;i++)
		if(q[i].op==1)
			printf("%d\n",c[query(q[i].x-1,q[i].y,q[i].k)]);
		else
		{
			update(q[i].x,a[q[i].x],-1);
			update(q[i].x,q[i].y,1);
			a[q[i].x]=q[i].y;
		}
	return 0;
}