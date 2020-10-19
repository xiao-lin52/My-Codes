#include<bits/stdc++.h>
#define re register int
#define N 1000010
using namespace std;
int n,m,len,num,a[N],belong[N],l[1010],r[1010],add[1010];
vector<int> g[1010];
inline int read(int &x)
{
	register char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
}
inline void qk(int x)
{
	g[x].clear();
	for(re i=l[x];i<=r[x];i++)
		g[x].push_back(a[i]);
	sort(g[x].begin(),g[x].end());
}
inline void update(int x,int y,int k)
{
	for(re i=x;i<=min(r[belong[x]],y);i++)
		a[i]+=k;
	qk(belong[x]);
	if(belong[x]!=belong[y])
	{
		for(re i=belong[x]+1;i<=belong[y]-1;i++)
			add[i]+=k;
		for(re i=l[belong[y]];i<=y;i++)
			a[i]+=k;
		qk(belong[y]);
	}
}
int query(int x,int y,int k)
{
	int sum=0;
	for(re i=x;i<=min(r[belong[x]],y);i++)
		if(a[i]>=k-add[belong[i]])
			sum++;
	if(belong[x]!=belong[y])
	{
		for(re i=belong[x]+1;i<=belong[y]-1;i++)
			sum+=g[i].end()-lower_bound(g[i].begin(),g[i].end(),k-add[i]);
		for(re i=l[belong[y]];i<=y;i++)
			if(a[i]>=k-add[belong[i]])
				sum++;
	}
	return sum;
}
int main()
{
	read(n);
	read(m);
	len=sqrt(n);
	num=(n-1)/len+1;
	for(re i=1;i<=n;i++)
	{
		read(a[i]);
		belong[i]=(i-1)/len+1;
	}
	for(re i=1;i<=num;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=min(i*len,n);
		qk(i);
	}
	for(re i=1;i<=m;i++)
	{
		char op;
		int l,r,k;
		cin>>op>>l>>r>>k;
		if(op=='M')
			update(l,r,k);
		else
			cout<<query(l,r,k)<<endl;
	}
	return 0;
}
