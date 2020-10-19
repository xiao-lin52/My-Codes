//这代码貌似是错的，但我并不会改。。。
#include<bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;
int n,m,num,l,r,len,a[N],cnt[N],ans[N],belong[N];
set<int> rec;
struct Query
{
	int x;
	int y;
	int k;
	int id;
	bool operator < (Query const &a) const
	{
		return (k^a.k) ? k<a.k : (belong[x]^belong[a.x]) ? belong[x]<belong[a.x] : (belong[x]&1) ? y<a.y : y>a.y;
	}
};
Query q[N];
void add(int i,int l,int r,int p)
{
	cnt[a[i]]++;
	if(cnt[a[i]]*p>(r-l+1))
		rec.insert(a[i]);
}
void del(int i,int l,int r,int p)
{
	cnt[a[i]]--;
	if(cnt[a[i]]*p<=(r-l+1))
		rec.erase(a[i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	len=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		belong[i]=(i-1)/len+1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].k);
		q[i].id=i;
	}
	sort(q+1,q+1+m);
	for(int i=1;i<=n;i++)
	{
		if(q[i].k!=q[i-1].k)
		{
			memset(cnt,0,sizeof(cnt));
			rec.clear();
			l=q[i].x;
			r=l-1;
		}
		while(l<q[i].x)
			del(l++,q[i].x,q[i].y,q[i].k);
		while(l>q[i].x)
			add(--l,q[i].x,q[i].y,q[i].k);
		while(r<q[i].y)
			add(++r,q[i].x,q[i].y,q[i].k);
		while(r>q[i].y)
			del(r--,q[i].x,q[i].y,q[i].k);
		if(rec.empty())
			ans[q[i].id]=-1;
		else
			ans[q[i].id]=*rec.begin();
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
