#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 100010
#define B 700
#define Col 200
#define SIZE 50001
namespace IO
{
	void read(int &x)
	{
		x=0;
		char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		while(isdigit(ch))
		{
			x=x*10+(ch^48);
			ch=getchar();
		}
	}
	void print(int x)
	{
		if(!x)
			putchar('0');
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		int t=0,out[30];
		while(x)
		{
			out[++t]=x%10;
			x/=10;
		}
		while(t)
			putchar(out[t--]^48);
		putchar('\n');
	}
}
using namespace IO;
using namespace std;
struct Stack
{
	int t;
	int st[Col];
	void push(int x) { st[++t]=x; }
	void pop() { t--; }
	int top() { return st[t]; }
	void clear() { t=0; }
};
class Hash
{
	private:
		struct node
		{
			int key;
			int data;
			node *next;
		};
		node *head[SIZE];
	public:
		int& operator [](int x)
		{
			int p=x*x%SIZE;
			if(head[p]==NULL)
			{
				head[p]=new node;
				head[p]->key=x;
				head[p]->next=NULL;
				return head[p]->data=0;
			}
			for(node *it=head[p];it!=NULL;it=it->next)
			{
				if(it->key==x)
					return it->data;
				if(it->next==NULL)
				{
					it->next=new node;
					it->next->key=x;
					it->next->next=NULL;
					return it->data=0;
				}
			}
		}
		void erase(int x)
		{
			int p=x*x%SIZE;
			if(head[p]==NULL)
				return;
			if(head[p]!=NULL&&head[p]->next==NULL)
			{
				delete head[p];
				head[p]=NULL;
				return;
			}
			for(node *it=head[p];it->next!=NULL;it=it->next)
			{
				if(it->next->key==x)
				{
					node *tmp=it->next;
					it->next=it->next->next;
					delete tmp;
					return;
				}
			}
		}
		void del(node **p)
		{
			if((*p)->next!=NULL)
				del(&(*p)->next);
			delete *p;
			*p=NULL;
		}
		void clear()
		{
			for(int i=0;i<SIZE;i++)
				if(head[i]!=NULL)
					del(&head[i]);
		}
};
struct Process
{
	int val;
	int data;
	int id;
};
bool cmp1(Process a,Process b)
{
	return a.data<b.data;
}
bool cmp2(Process a,Process b)
{
	return a.id<b.id;
}
Process b[N];
int n,m,f,lastans,a[N];
int len,num,l[B],r[B],tag[B],belong[N];
int mn[B][Col],mx[B][Col],val[B][Col],cnt[B][Col],dis[B][Col][Col];
Stack col[B];
Hash q[B];
inline void get_col(int x,int k,int &p)
{
	if(!q[x][k])
	{
		q[x][k]=col[x].top();
		col[x].pop();
		val[x][q[x][k]]=k;
	}
	p=q[x][k];
}
inline void push_down(int x)
{
	if(!tag[x])
		return;
	memset(cnt[x],0,sizeof(cnt[x]));
	memset(dis[x],inf,sizeof(dis[x]));
	memset(mn[x],0,sizeof(mn[x]));
	memset(mx[x],0,sizeof(mx[x]));
	memset(val[x],0,sizeof(val[x]));
	col[x].clear();
	q[x].clear();
	for(int i=r[x]-l[x]+1;i>=2;i--)
		col[x].push(i);
	q[x][tag[x]]=1;
	val[x][1]=tag[x];
	dis[x][1][1]=0;
	for(int i=l[x];i<=r[x];i++)
	{
		a[i]=1;
		cnt[x][1]++;
	}
	mn[x][1]=l[x];
	mx[x][1]=r[x];
	tag[x]=0;
}
inline void erase_col(int x,int y)
{
	push_down(belong[x]);
	for(int i=x;i<=y;i++)
	{
		cnt[belong[i]][a[i]]--;
		if(!cnt[belong[i]][a[i]])
		{
			col[belong[i]].push(a[i]);
			q[belong[i]].erase(val[belong[i]][a[i]]);
			val[belong[i]][a[i]]=0;
		}
	}
}
inline void qk(int x,int y)
{
	memset(mx[belong[x]],0,sizeof(mx[belong[x]]));
	memset(mn[belong[x]],0,sizeof(mn[belong[x]]));
	memset(dis[belong[x]],inf,sizeof(dis[belong[x]]));
	for(int i=l[belong[x]];i<=x;i++)
	{
		for(int j=i;j<=x;j++)
			dis[belong[i]][a[i]][a[j]]=dis[belong[i]][a[j]][a[i]]=min(dis[belong[i]][a[i]][a[j]],j-i);
		for(int j=y;j<=r[belong[x]];j++)
			dis[belong[i]][a[i]][a[j]]=dis[belong[i]][a[j]][a[i]]=min(dis[belong[i]][a[i]][a[j]],j-i);
	}
	for(int i=y;i<=r[belong[x]];i++)
		for(int j=i;j<=r[belong[x]];j++)
			dis[belong[i]][a[i]][a[j]]=dis[belong[i]][a[j]][a[i]]=min(dis[belong[i]][a[i]][a[j]],j-i);
	for(int i=l[belong[x]];i<=r[belong[x]];i++)
		if(!mn[belong[x]][a[i]])
			mn[belong[x]][a[i]]=i;
	for(int i=r[belong[x]];i>=l[belong[x]];i--)
		if(!mx[belong[x]][a[i]])
			mx[belong[x]][a[i]]=i;
}
inline void update(int x,int y,int k)
{
	int p;
	erase_col(x,min(r[belong[x]],y));
	get_col(belong[x],k,p);
	for(int i=x;i<=min(r[belong[x]],y);i++)
	{
		a[i]=p;
		cnt[belong[x]][p]++;
	}
	qk(x,min(r[belong[x]],y));
	if(belong[x]!=belong[y])
	{
		for(int i=belong[x]+1;i<=belong[y]-1;i++)
			tag[i]=k;
		erase_col(l[belong[y]],y);
		get_col(belong[y],k,p);
		for(int i=l[belong[y]];i<=y;i++)
		{
			a[i]=p;
			cnt[belong[y]][p]++;
		}
		qk(l[belong[y]],y);
	}
}
inline void query(int x,int y)
{
	int ans=inf,xlast=0,ylast=0;
	for(int i=1;i<=num;i++)
	{
		if(tag[i])
		{
			if(tag[i]==x&&tag[i]==y)
			{
				ans=0;
				break;
			}
			if(tag[i]==x)
			{
				if(ylast)
					ans=min(ans,l[i]-ylast);
				xlast=r[i];
			}
			if(tag[i]==y)
			{
				if(xlast)
					ans=min(ans,l[i]-xlast);
				ylast=r[i];
			}
			continue;
		}
		int px=q[i][x],py=q[i][y];
		if(px&&ylast)
			ans=min(ans,mn[i][px]-ylast);
		if(py&&xlast)
			ans=min(ans,mn[i][py]-xlast);
		if(px&&py)
			ans=min(ans,dis[i][px][py]);
		if(px)
			xlast=mx[i][px];
		else
			q[i].erase(x);
		if(py)
			ylast=mx[i][py];
		else
			q[i].erase(y);
	}
	if(ans==inf)
	{
		print(-1);
		ans=0;
	}
	else
		print(ans);
	lastans=ans;
}
int main()
{
	memset(dis,inf,sizeof(dis));
	read(n);
	read(m);
	read(f);
	len=sqrt(n)/2+1;
	num=(n-1)/len+1;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		b[i].data=a[i];
		b[i].id=i;
		belong[i]=(i-1)/len+1;
	}
	for(int i=1;i<=num;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=min(len*i,n);
	}
	for(int i=1;i<=num;i++)
	{
		register int tmp=0;
		sort(b+l[i],b+r[i]+1,cmp1);
		for(int j=l[i];j<=r[i];j++)
		{
			if(j==l[i]||b[j].data!=b[j-1].data)
				tmp++;
			b[j].val=tmp;
		}
		sort(b+l[i],b+r[i]+1,cmp2);
		for(int j=l[i];j<=r[i];j++)
		{
			q[i][a[j]]=b[j].val;
			val[i][b[j].val]=a[j];
			a[j]=b[j].val;
			cnt[i][a[j]]++;
		}
		for(int j=l[i];j<=r[i];j++)
			if(!mn[i][a[j]])
				mn[i][a[j]]=j;
		for(int j=r[i];j>=l[i];j--)
			if(!mx[i][a[j]])
				mx[i][a[j]]=j;
		for(int j=r[i]-l[i]+1;j>=tmp+1;j--)
			col[i].push(j);
		for(int j=l[i];j<=r[i];j++)
			for(int k=j;k<=r[i];k++)
				dis[i][a[j]][a[k]]=dis[i][a[k]][a[j]]=min(dis[i][a[j]][a[k]],k-j);
	}
	for(int i=1;i<=m;i++)
	{
		int op,l,r,k;
		read(op);
		read(l);
		read(r);
		if(f)
		{
			l^=lastans;
			r^=lastans;
		}
		if(op==1)
		{
			read(k);
			if(f)
				k^=lastans;
			update(l,r,k);
		}
		else
			query(l,r);
	}
	for(int i=1;i<=num;i++)
		q[i].clear();
	return 0;
}