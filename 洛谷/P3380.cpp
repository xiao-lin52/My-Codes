#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,inf=2147483647,mod=19260817;
struct SegTree
{
	int l;
	int r;
};
SegTree tree[N<<2];
int n,m,sed,a[N];
int tot,rt[N<<2],val[N*300],siz[N*300],num[N*300],rnd[N*300],son[N*300][2];
int rd()
{
	return sed=1ll*sed*sed%mod;
}
inline void push_up(int i)
{
	siz[i]=siz[son[i][0]]+siz[son[i][1]]+num[i];
}
inline void spin(int &i,int s)
{
	int t=son[i][s];
	son[i][s]=son[t][s^1];
	son[t][s^1]=i;
	push_up(i);
	push_up(t);
	i=t;
}
void ins(int &i,int k)
{
	if(!i)
	{
		i=++tot;
		rnd[i]=rd();
		val[i]=k;
		siz[i]=num[i]=1;
		return;
	}
	if(val[i]==k)
	{
		siz[i]++;
		num[i]++;
		return;
	}
	int t=(val[i]<k);
	ins(son[i][t],k);
	if(rnd[son[i][t]]<rnd[i])
		spin(i,t);
	push_up(i);
}
void del(int &i,int k)
{
	if(!i)
		return;
	if(val[i]==k)
	{
		if(num[i]>1)
		{
			num[i]--;
			siz[i]--;
			return;
		}
		if(!son[i][0]&&!son[i][1])
			i=0;
		else if(!son[i][0])
		{
			spin(i,1);
			del(son[i][0],k);
		}
		else if(!son[i][1])
		{
			spin(i,0);
			del(son[i][1],k);
		}
		else
		{
			int t=(rnd[son[i][0]]<rnd[son[i][1]]);
			spin(i,t);
			del(son[i][t^1],k);
		}
		return;
	}
	int t=(val[i]<k);
	del(son[i][t],k);
	push_up(i);
}
int getrnk(int i,int k)
{
	if(!i)
		return 0;
	if(val[i]==k)
		return siz[son[i][0]];
	if(val[i]>k)
		return getrnk(son[i][0],k);
	if(val[i]<k)
		return getrnk(son[i][1],k)+siz[son[i][0]]+num[i];
}
int getpre(int i,int k)
{
	if(!i)
		return -inf;
	if(val[i]>=k)
		return getpre(son[i][0],k);
	else
		return max(val[i],getpre(son[i][1],k));
}
int getsuf(int i,int k)
{
	if(!i)
		return inf;
	if(val[i]<=k)
		return getsuf(son[i][1],k);
	else
		return min(val[i],getsuf(son[i][0],k));
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	for(int j=l;j<=r;j++)
		ins(rt[i],a[j]);
	if(l==r)
		return;
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
}
int askrnk(int i,int x,int y,int k)
{
	int sum=0;
	if(!i)
		return 0;
	if(tree[i].l>=x&&tree[i].r<=y)
		return getrnk(rt[i],k);
	if(x<=tree[i<<1].r)
		sum+=askrnk(i<<1,x,y,k);
	if(y>=tree[i<<1|1].l)
		sum+=askrnk(i<<1|1,x,y,k);
	return sum;
}
int askkth(int x,int y,int k)
{
	int lt=0,rt=1e8;
	while(lt<rt)
	{
		int mid=(lt+rt+1)>>1;
		if(askrnk(1,x,y,mid)<k)
			lt=mid;
		else
			rt=mid-1;
	}
	return rt;
}
void update(int i,int x,int k)
{
	del(rt[i],a[x]);
	ins(rt[i],k);
	if(tree[i].l==tree[i].r)
		return;
	if(x<=tree[i<<1].r)
		update(i<<1,x,k);
	else
		update(i<<1|1,x,k);
}
int askpre(int i,int x,int y,int k)
{
	int ans=-inf;
	if(tree[i].l>=x&&tree[i].r<=y)
		return getpre(rt[i],k);
	if(x<=tree[i<<1].r)
		ans=max(ans,askpre(i<<1,x,y,k));
	if(y>=tree[i<<1|1].l)
		ans=max(ans,askpre(i<<1|1,x,y,k));
	return ans;
}
int asksuf(int i,int x,int y,int k)
{
	int ans=inf;
	if(tree[i].l>=x&&tree[i].r<=y)
		return getsuf(rt[i],k);
	if(x<=tree[i<<1].r)
		ans=min(ans,asksuf(i<<1,x,y,k));
	if(y>=tree[i<<1|1].l)
		ans=min(ans,asksuf(i<<1|1,x,y,k));
	return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("P3380_2.in","r",stdin);
	freopen("data.out","w",stdout);
	#endif
	sed=time(0)%mod;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	while(m--)
	{
		int op,x,y,k;
		scanf("%d",&op);
		if(op==1||op==2||op==4||op==5)
			scanf("%d%d%d",&x,&y,&k);
		else
			scanf("%d%d",&x,&k);
		if(op==1)
			printf("%d\n",askrnk(1,x,y,k)+1);
		else if(op==2)
			printf("%d\n",askkth(x,y,k));
		else if(op==3)
		{
			update(1,x,k);
			a[x]=k;
		}
		else if(op==4)
			printf("%d\n",askpre(1,x,y,k));
		else if(op==5)
			printf("%d\n",asksuf(1,x,y,k));
	}
	return 0;
}