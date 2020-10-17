#include<bits/stdc++.h>
#define ll int
#define N 100010
#define re register int
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
inline void print(ll x)
{
	if(!x)
	{
		putchar('0');
		putchar('\n');
		return;
	}
	stack<int> st;
	while(x)
	{
		st.push(x%10);
		x/=10;
	}
	while(st.size())
	{
		putchar(st.top()+'0');
		st.pop();
	}
	putchar('\n');
}
ll n,c,m,num,len,lastans,a[N],belong[N],l[N],r[N];
bitset<N> b[3010],k[3010];
inline ll query(ll x,ll y)
{
	bitset<N> ans,p;
	for(re i=x;i<=min(y,r[belong[x]]);i++)
	{
		ans[a[i]]=ans[a[i]]^1;
		p[a[i]]=p[a[i]]|1;
	}
	for(re i=belong[x]+1;i<=belong[y]-1;i++)
	{
		ans^=b[i];
		p|=k[i];
	}
	if(belong[x]!=belong[y])
		for(re i=l[belong[y]];i<=y;i++)
		{
			ans[a[i]]=ans[a[i]]^1;
			p[a[i]]=p[a[i]]|1;
		}
	return p.count()-ans.count();
}
int main()
{
	n=read();
	c=read();
	m=read();
	len=sqrt(n);
	num=(n-1)/len+1;
	for(re i=1;i<=n;i++)
	{
		a[i]=read();
		belong[i]=(i-1)/len+1;
		b[belong[i]][a[i]]=b[belong[i]][a[i]]^1;
		k[belong[i]][a[i]]=k[belong[i]][a[i]]|1;
	}
	for(re i=1;i<=num;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=min(i*len,n);
	}
	for(re i=1;i<=m;i++)
	{
		ll x=read(),y=read();
		x=(x+lastans)%n+1;
		y=(y+lastans)%n+1;
		if(x>y)
			swap(x,y);
		lastans=query(x,y);
		print(lastans);
	}
	return 0;
}
