#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,inf=2147483647;
struct Query
{
	int op,x,y,k;
};
Query q[N];
int n,m,tot,qwq,a[N],c[N*2],rt[N],ls[N*200],rs[N*200],dat[N*200],mx[N*200],mn[N*200];
vector<int> st,ed;
inline void push_up(int i)
{
	dat[i]=dat[ls[i]]+dat[rs[i]];
	mx[i]=max(dat[ls[i]] ? mx[ls[i]] : -inf,dat[rs[i]] ? mx[rs[i]] : -inf);
}
void modify(int &i,int l,int r,int x,int k)
{
	if(!i)
		i=++tot;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(x<=mid)
		modify(ls[i],l,mid,x,k);
	else
		modify(rs[i],mid+1,r,x,k);
	push_up(i);
}
int getrnk(int l,int r,int k)
{
	if(l==r)
		return 1;
	int s1=0,s2=0;
	for(int i=0;i<st.size();i++)
		s1+=dat[ls[st[i]]];
	for(int i=0;i<ed.size();i++)
		s2+=dat[ls[ed[i]]];
	int mid=(l+r)>>1;
	if(k<=mid)
	{
		for(int i=0;i<st.size();i++)
			st[i]=ls[st[i]];
		for(int i=0;i<ed.size();i++)
			ed[i]=ls[ed[i]];
		return getrnk(l,mid,k);
	}
	else
	{
		for(int i=0;i<st.size();i++)
			st[i]=rs[st[i]];
		for(int i=0;i<ed.size();i++)
			ed[i]=rs[ed[i]];
		return s2-s1+getrnk(mid+1,r,k);
	}
}
int getkth(int l,int r,int k)
{
	if(l==r)
		return l;
	int s1=0,s2=0;
	for(int i=0;i<st.size();i++)
		s1+=dat[ls[st[i]]];
	for(int i=0;i<ed.size();i++)
		s2+=dat[ls[ed[i]]];
	int mid=(l+r)>>1;
	if(s2-s1>=k)
	{
		for(int i=0;i<st.size();i++)
			st[i]=ls[st[i]];
		for(int i=0;i<ed.size();i++)
			ed[i]=ls[ed[i]];
		return getkth(l,mid,k);
	}
	else
	{
		for(int i=0;i<st.size();i++)
			st[i]=rs[st[i]];
		for(int i=0;i<ed.size();i++)
			ed[i]=rs[ed[i]];
		return getkth(mid+1,r,k-(s2-s1));
	}
}
int getpre(int l,int r,int k)
{
	int s1=0,s2=0;
	for(int i=0;i<st.size();i++)
		s1+=dat[ls[st[i]]];
	for(int i=0;i<ed.size();i++)
		s2+=dat[ls[ed[i]]];
	if(l==r)
		return s2-s1 ? l : -inf;
	int mid=(l+r)>>1;
	if(k<=mid)
	{
		for(int i=0;i<st.size();i++)
			st[i]=ls[st[i]];
		for(int i=0;i<ed.size();i++)
			ed[i]=ls[ed[i]];
		return getpre(l,mid,k);
	}
	else
	{
		for(int i=0;i<st.size();i++)
			st[i]=rs[st[i]];
		for(int i=0;i<ed.size();i++)
			ed[i]=rs[ed[i]];
		return getpre(mid+1,r,k);
	}
}
int getsuf(int l,int r,int k)
{
	if(l==r)
		return l;
	int s1=0,s2=0;
	
	for(int i=0;i<st.size();i++)
		s1+=dat[ls[st[i]]];
	for(int i=0;i<ed.size();i++)
		s2+=dat[ls[ed[i]]];
	int mid=(l+r)>>1;
	if(k>=mid+1)
	{
		for(int i=0;i<st.size();i++)
			st[i]=ls[st[i]];
		for(int i=0;i<ed.size();i++)
			ed[i]=ls[ed[i]];
		return getrnk(l,mid,k);
	}
	else
	{
		for(int i=0;i<st.size();i++)
			st[i]=rs[st[i]];
		for(int i=0;i<ed.size();i++)
			ed[i]=rs[ed[i]];
		return s2-s1+getrnk(mid+1,r,k);
	}
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
		scanf("%d%d",&q[i].op,&q[i].x);
		if(q[i].op==1||q[i].op==2||q[i].op==4||q[i].op==5)
			scanf("%d%d",&q[i].y,&q[i].k);
		else
			scanf("%d",&q[i].k);
		if(q[i].op!=2)
			c[++qwq]=q[i].k;
	}
	sort(c+1,c+1+qwq);
	qwq=unique(c+1,c+1+qwq)-c-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(c+1,c+1+qwq,a[i])-c;
	}
	return 0;
}