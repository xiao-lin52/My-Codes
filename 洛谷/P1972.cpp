//MD我真是见鬼了，这道题居然卡莫队，卡了一下午常数都没卡过去，最慢的一个点1.65s
//chen_zhe你不厚道！！！
#include<bits/stdc++.h>
#define N 1000010
#define re register int
using namespace std;
inline char get_char()
{
    static char buf[1000001],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline void read(int &num){
    register char c;
    while(isspace(c=get_char()));
    while(num=num*10+c-48,isdigit(c=get_char()));
}
struct query
{
	int x;
	int y;
	int id;
};
query q[N];
int n,m,ans[N],cnt[N],a[N],belong[N];
inline bool cmp(query a,query b)
{
	return (belong[a.x]^belong[b.x]) ? belong[a.x]<belong[b.x] : ((belong[a.x]&1) ? a.y<b.y : a.y>b.y);
}
int main()
{
	read(n);
	for(re i=1;i<=n;++i)
		read(a[i]);
	read(m);
	re len=n/sqrt(m);
	for(re i=1;i<=m;++i)
		read(q[i].x),read(q[i].y),q[i].id=i;
	for(re i=1;i<=n;i+=4)
		belong[i]=(i-1)/len+1,belong[i+1]=i/len+1,belong[i+2]=(i+1)/len+1,belong[i+3]=(i+2)/len+1;
	sort(q+1,q+1+m,cmp);
	register int l=1,r=0,num=0;
	for(re i=1;i<=m;++i)
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
	for(re i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}
