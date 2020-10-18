#include<bits/stdc++.h>
#define N 1000010
using namespace std;
inline void read(int &x)
{
	register char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
}
inline void print(int x)
{
	if(!x)
		putchar('0');
	stack<char> st;
	while(x)
	{
		st.push(x%10+'0');
		x/=10;
	}
	while(st.size())
	{
		putchar(st.top());
		st.pop();
	}
	putchar('\n');
}
struct query
{
	int x;
	int y;
	int id;
};
query q[N];
int n,m,len,l=1,r,num,ans[N],cnt[N],a[N],belong[N];
inline bool cmp(query a,query b)
{
	return (belong[a.x]^belong[b.x]) ? belong[a.x]<belong[b.x] : ((belong[a.x]&1) ? a.y<b.y : a.y>b.y);
}
inline void add(int x)
{
	if(!cnt[a[x]])
		num++;
	cnt[a[x]]++;
}
inline void del(int x)
{
	cnt[a[x]]--;
	if(!cnt[a[x]])
		num--;
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	read(m);
	len=n/sqrt(m);
	for(int i=1;i<=m;i++)
	{
		read(q[i].x);
		read(q[i].y);
		q[i].id=i;
	}
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/len+1;
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].x)
			num-=!--cnt[a[l++]];
		while(l>q[i].x)
			num+=!cnt[a[--l]]++;
		while(r<q[i].y)
			num+=!cnt[a[++r]]++;
		while(r>q[i].y)
			num-=!--cnt[a[r--]];
		ans[q[i].id]=num;
	}
	for(int i=1;i<=m;i++)
		print(ans[i]);
	return 0;
}
