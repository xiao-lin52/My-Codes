#include<bits/stdc++.h>
#define Abs(x) (x>0 ? x : -x)
using namespace std;
const int N=4e4+10,mod=1e7+7,inf=1e9;
int n,a,tot,sed,ans,rt,val[N],rnd[N],son[N][2];
int rd()
{
	return sed=1ll*sed*20060209ll%mod;
}
void spin(int &p,int s)
{
	int t=son[p][s];
	son[p][s]=son[t][s^1];
	son[t][s^1]=p;
	p=t;
}
void ins(int &p,int k)
{
	if(!p)
	{
		p=++tot;
		val[p]=k;
		rnd[p]=rd();
		return;
	}
	if(val[p]==k)
		return;
	int t=(val[p]<k);
	ins(son[p][t],k);
	if(rnd[son[p][t]]>rnd[p])
		spin(p,t);
}
int getpre(int p,int k)
{
	if(!p)
		return -inf;
	if(val[p]>k)
		return getpre(son[p][0],k);
	else
		return max(val[p],getpre(son[p][1],k));
}
int getsuf(int p,int k)
{
	if(!p)
		return inf;
	if(val[p]<k)
		return getsuf(son[p][1],k);
	else
		return min(val[p],getsuf(son[p][0],k));
}
int main()
{
	scanf("%d",&n);
	sed=time(0)%mod;
	scanf("%d",&a);
	ins(rt,a);
	ans+=a;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
		ans+=min(a-getpre(rt,a),getsuf(rt,a)-a);
		ins(rt,a);
	}
	printf("%d",ans);
	return 0;
}