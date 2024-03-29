#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	char buf[1<<23],*p1=buf,*p2=buf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	#define isdigit(c) (c>=48&&c<=57)
	#define isalpha(c) (c>=65&&c<=90)
	template<typename T> inline void read(T &x)
	{
		x=0;
		register char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
const int N=1e6+10;
struct SegTree
{
	int ls;
	int rs;
	int data;
};
SegTree tree[N*21];
int n,m,tot,ans,rt[N],lst[N];
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
int query(int i,int j,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(x==mid)
		return tree[tree[j].ls].data-tree[tree[i].ls].data;
	if(x<mid)
		return query(tree[i].ls,tree[j].ls,l,mid,x);
	else
		return tree[tree[j].ls].data-tree[tree[i].ls].data+query(tree[i].rs,tree[j].rs,mid+1,r,x);
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		int a;
		read(a);
		update(rt[i-1],rt[i],0,n-1,lst[a]);
		lst[a]=i;
	}
	read(m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		read(x,y);
		printf("%d\n",ans=query(rt[x-1],rt[y],0,n-1,x-1));
	}
	return 0;
}