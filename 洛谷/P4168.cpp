#include<bits/stdc++.h>
#define N 100010
#define re register int
using namespace std;
inline int read()
{
	re x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
inline void print(int x)
{
	stack<int> st;
	while(x){st.push(x%10);x/=10;}
	while(st.size()){putchar(st.top()+48);st.pop();}
	putchar('\n');
}
int n,l,m,len,q,num,b[N],c[N],belong[N],cnt[N],p[1010][1010];
map<int,int> t;
vector<int> g[N];
inline int findsum(int l,int r,int x)
{
	return upper_bound(g[x].begin(),g[x].end(),r)-lower_bound(g[x].begin(),g[x].end(),l);
}
inline int query(int x,int y)
{
	memset(cnt,0,sizeof(cnt));
	re ans=p[belong[x]+1][belong[y]-1];
	cnt[ans]=findsum(x,y,ans);
	for(re i=x;i<=min(y,belong[x]*len);i++)
		if(!cnt[b[i]])
		{
			cnt[b[i]]=findsum(x,y,b[i]);
			if(cnt[b[i]]>cnt[ans]||(cnt[b[i]]==cnt[ans]&&c[b[i]]<c[ans]))
				ans=b[i];
		}
	for(re i=max((belong[y]-1)*len+1,x);i<=y;i++)
		if(!cnt[b[i]])
		{
			cnt[b[i]]=findsum(x,y,b[i]);
			if(cnt[b[i]]>cnt[ans]||(cnt[b[i]]==cnt[ans]&&c[b[i]]<c[ans]))
				ans=b[i];
		}
	return q=c[ans];
}
int main()
{
	n=read();
	l=read();
	len=sqrt(n);
	num=(n-1)/len+1;
	for(re i=1;i<=n;i++)
	{
		b[i]=read();
		belong[i]=(i-1)/len+1;
		if(!t[b[i]])
		{
			t[b[i]]=++m;
			c[m]=b[i];
		}
		b[i]=t[b[i]];
		g[b[i]].push_back(i);
	}
	for(re i=1;i<=num;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for(re j=i;j<=num;j++)
		{
			p[i][j]=p[i][j-1];
			for(re k=(j-1)*len+1;k<=j*len;k++)
			{
				cnt[b[k]]++;
				if(cnt[b[k]]>cnt[p[i][j]]||(cnt[b[k]]==cnt[p[i][j]]&&c[b[k]]<c[p[i][j]]))
					p[i][j]=b[k];
			}
		}
	}
	for(re i=1;i<=l;i++)
	{
		re x=read(),y=read();
		x=((x+q-1)%n)+1;
		y=((y+q-1)%n)+1;
		if(x>y)
			swap(x,y);
		print(query(x,y));
	}
	return 0;
}
