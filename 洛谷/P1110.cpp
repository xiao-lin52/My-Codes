#include<bits/stdc++.h>
#define Abs(x) ((x)>0 ? (x) : -(x))
using namespace std;
namespace IO
{
	char buf[1<<25],*p1=buf,*p2=buf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
	#define isdigit(c) (c>=48&&c<=57)
	#define isalpha(c) (c>=65&&c<=90)
	template<typename T> inline void read(T &x)
	{
		x=0;
		register int f=1;
		register char ch=getchar();
		while(!isdigit(ch))
		{
			if(ch==45)
				f=-1;
			ch=getchar();
		}
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
		x*=f;
	}
	inline void reads(char x[])
	{
		register int cnt=0;
		register char ch=getchar();
		while(!isalpha(ch)&&ch!='_')
			ch=getchar();
		while(isalpha(ch)||ch=='_')
		{
			x[cnt]=ch;
			cnt++;
			ch=getchar();
		}
	}
	inline void readc(char &x)
	{
		register char ch=getchar();
		while(!isalpha(ch))
			ch=getchar();
		x=ch;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
const int N=1e6+10,inf=1e9;
int n,m,ans=inf,hd[N>>1],tl[N>>1];
priority_queue< int,vector<int>,greater<int> > tag,q;
struct Treap
{
	const int mod=1e6+7;
	int rt,tot,sed,val[N],num[N],rnd[N],son[N][2];
	inline int rd()
	{
		return sed=sed*20060209ll%mod;
	}
	inline void spin(int &p,int s)
	{
		int x=son[p][s];
		son[p][s]=son[x][s^1];
		son[x][s^1]=p;
		p=x;
	}
	void ins(int &p,int k)
	{
		if(!p)
		{
			p=++tot;
			val[p]=k;
			num[p]=1;
			rnd[p]=rd();
			return;
		}
		if(val[p]==k)
		{
			num[p]++;
			return;
		}
		int t=(val[p]<k);
		ins(son[p][t],k);
		if(rnd[son[p][t]]<rnd[p])
			spin(p,t);
	}
	void del(int &p,int k)
	{
		if(!p)
			return;
		if(val[p]==k)
		{
			if(num[p]>1)
			{
				num[p]--;
				return;
			}
			if(!son[p][0]&&!son[p][1])
				p=0;
			else if(!son[p][0])
				p=son[p][1];
			else if(!son[p][1])
				p=son[p][0];
			else
			{
				int t=(rnd[son[p][0]]>rnd[son[p][1]]);
				spin(p,t);
				del(son[p][t^1],k);
			}
			return;
		}
		int t=(val[p]<k);
		del(son[p][t],k);
	}
	int getmin(int p)
	{
		if(!son[p][0])
			return val[p];
		getmin(son[p][0]);
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
};
Treap sort_gap;
inline void update(int x,int k)
{
	if(x!=n)
	{
		tag.push(Abs(hd[x+1]-tl[x]));
		q.push(Abs(k-hd[x+1]));
	}
	q.push(Abs(k-tl[x]));
	ans=min(ans,min(k-sort_gap.getpre(sort_gap.rt,k),sort_gap.getsuf(sort_gap.rt,k)-k));
	sort_gap.ins(sort_gap.rt,k);
	tl[x]=k;
}
int main()
{
	sort_gap.sed=time(0);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		int k;
		read(k);
		if(i!=1)
			q.push(Abs(k-hd[i-1]));
		ans=min(ans,min(k-sort_gap.getpre(sort_gap.rt,k),sort_gap.getsuf(sort_gap.rt,k)-k));
		sort_gap.ins(sort_gap.rt,k);
		hd[i]=tl[i]=k;
	}
	for(int i=1;i<=m;i++)
	{
		char op[20];
		int x,y;
		reads(op);
		if(op[0]=='I')
		{
			read(x);
			read(y);
			update(x,y);
		}
		else if(op[4]=='G')
		{
			while(tag.size()&&tag.top()==q.top())
			{
				tag.pop();
				q.pop();
			}
			printf("%d\n",q.top());
		}
		else
			printf("%d\n",ans);
	}
	return 0;
}