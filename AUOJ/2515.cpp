#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int n,k,m,a[N],b[N],l,r,vis[N];
inline void read(int &x)
{
	register char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ch=getchar();
	while(ch>='0'&&ch<='9') { x=x*10+ch^48;ch=getchar(); }
}
int dfs(int s)
{
	if(s==r+1)
		return 1;
	for(int i=1;i<=k;i++)
		if(!vis[i]&&(a[i]==s||b[i]==s))
		{
			vis[i]=1;
			if(dfs(s+1))
				return 1;
			vis[i]=0;
		}
	return 0;
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	read(n);
	read(k);
	for(int i=1;i<=k;i++)
	{
		read(a[i]);
		read(b[i]);
	}
	read(m);
	for(int i=1;i<=m;i++)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&l,&r);
		if(dfs(l))
			printf("Yes\n");
		else
			printf("No\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
