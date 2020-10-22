#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,m,p,len,k,k1,lastc,l=1,r,t,ans[N],cnt[N],cnt1[N],a[N];
struct Query
{
	int x;
	int y;
	int z;
	int id;
	bool operator < (Query const &a) const
	{
		return ((x/len)^(a.x/len)) ? x/len<a.x/len : ((y/len)^(a.y/len)) ? y/len<a.y/len : z<a.z;
	}
};
struct Change
{
	int p;
	int v;
};
Query q[N];
Change c[N];
vector<int> rec;
bitset<N> num;
void add(int i)
{
	cnt1[cnt[a[i]]]--;
	if(!cnt1[cnt[a[i]]])
		num[cnt[a[i]]]=1;
	cnt[a[i]]++;
	if(!cnt1[cnt[a[i]]])
		num[cnt[a[i]]]=0;
	cnt1[cnt[a[i]]]++;
}
void del(int i)
{
	cnt1[cnt[a[i]]]--;
	if(!cnt1[cnt[a[i]]])
		num[cnt[a[i]]]=1;
	cnt[a[i]]--;
	if(!cnt1[cnt[a[i]]])
		num[cnt[a[i]]]=0;
	cnt1[cnt[a[i]]]++;
}
int main()
{
	scanf("%d%d",&n,&m);
	len=(int)pow(n,2.0/3.0);
	rec.push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		rec.push_back(a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
			q[++k]=Query{l,r,lastc,k};
		else
		{
			k1++;
			lastc=k1;
			rec.push_back(r);
			c[k1]=Change{l,r};
		}
	}
	sort(rec.begin(),rec.end());
	rec.erase(unique(rec.begin(),rec.end()),rec.end());
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(rec.begin(),rec.end(),a[i])-rec.begin();
	for(int i=1;i<=k1;i++)
		c[i].v=lower_bound(rec.begin(),rec.end(),c[i].v)-rec.begin();
	sort(q+1,q+1+k);
	cnt1[0]=0x3f3f3f3f;
	num.set();
	num[0]=0;
	for(int i=1;i<=k;i++)
	{
		while(l>q[i].x)
			add(--l);
		while(r<q[i].y)
			add(++r);
		while(l<q[i].x)
			del(l++);
		while(r>q[i].y)
			del(r--);
		while(t<q[i].z)
		{
			t++;
			if(l<=c[t].p&&r>=c[t].p)
			{
				del(c[t].p);
				swap(a[c[t].p],c[t].v);
				add(c[t].p);
			}
			else
				swap(a[c[t].p],c[t].v);
		}
		while(t>q[i].z)
		{
			if(l<=c[t].p&&r>=c[t].p)
			{
				del(c[t].p);
				swap(a[c[t].p],c[t].v);
				add(c[t].p);
			}
			else
				swap(a[c[t].p],c[t].v);
			t--;
		}
		ans[q[i].id]=num._Find_first();
	}
	for(int i=1;i<=k;i++)
		printf("%d\n",ans[i]);
	return 0;
}