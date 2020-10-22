#include<bits/stdc++.h>
#define N 200010
#define Col 1000010
namespace IO
{
	void read(int &x)
	{
		x=0;
		register char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		while(isdigit(ch))
			x=x*10+(ch^48),ch=getchar();
	}
	void read(char &x)
	{
		register char ch=getchar();
		while(!isalpha(ch))
			ch=getchar();
		x=ch;
	}
	void print(int x)
	{
		if(!x)
			putchar('0');
		if(x<0)
			putchar('-'),x=-x;
		register int t=0,out[30];
		while(x)
			out[++t]=x%10,x/=10;
		while(t)
			putchar(out[t--]^48);
		putchar('\n');
	}
}
using namespace IO;
using namespace std;
int n,m,k,k1,len,lastc,num,cnt[Col],a[N],ans[N],belong[N];
struct Query
{
	int x;
	int y;
	int b;
	int id;
	bool operator < (Query const &a) const
	{
		return (belong[x]^belong[a.x]) ? belong[x]<belong[a.x] : (belong[y]^belong[a.y]) ? belong[y]<belong[a.y] : b<a.b;
	}
};
struct Change
{
	int p;
	int col;
};
Query q[N];
Change c[N];
int main()
{
	read(n);
	read(m);
	len=(int)pow(n,2.0/3.0);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		belong[i]=(i-1)/len+1;
	}
	for(int i=1;i<=m;i++)
	{
		char op;
		int a,b;
		read(op);
		read(a);
		read(b);
		if(op=='Q')
			q[++k]=Query{a,b,lastc,k};
		else
		{
			c[++k1]=Change{a,b};
			lastc=k1;
		}
	}
	sort(q+1,q+1+k);
	register int l=1,r=0,t=0;
	for(int i=1;i<=k;i++)
	{
		while(l<q[i].x)
			num-=!--cnt[a[l++]];
		while(l>q[i].x)
			num+=!cnt[a[--l]]++;
		while(r<q[i].y)
			num+=!cnt[a[++r]]++;
		while(r>q[i].y)
			num-=!--cnt[a[r--]];
		while(t<q[i].b)
		{
			t++;
			if(l<=c[t].p&&r>=c[t].p)
				num-=!--cnt[a[c[t].p]],num+=!cnt[c[t].col]++;
			swap(c[t].col,a[c[t].p]);
		}
		while(t>q[i].b)
		{
			if(l<=c[t].p&&r>=c[t].p)
				num-=!--cnt[a[c[t].p]],num+=!cnt[c[t].col]++;
			swap(c[t].col,a[c[t].p]);
			t--;
		}
		ans[q[i].id]=num;
	}
	for(int i=1;i<=k;i++)
		print(ans[i]);
	return 0;
}