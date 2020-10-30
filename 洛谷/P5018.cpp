#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,ans=1,in[N],a[N],l[N],r[N],siz[N];
void pre(int u)
{
	siz[u]=1;
	if(l[u]!=-1)
	{
		pre(l[u]);
		siz[u]+=siz[l[u]];
	}
	if(r[u]!=-1)
	{
		pre(r[u]);
		siz[u]+=siz[r[u]];
	}
}
int dfs(int u1,int u2)
{
	if(u1==-1&&u2==-1)
		return 1;
	if((u1==-1&&u2!=-1)||(u1!=-1&&u2==-1)||siz[u1]!=siz[u2]||a[u1]!=a[u2])
		return 0;
	if(dfs(l[u1],r[u2])&&dfs(r[u1],l[u2]))
		return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		if(l[i]!=-1) in[l[i]]++;
		if(r[i]!=-1) in[r[i]]++;
	}
	for(int i=1;i<=n;i++)
		if(!in[i])
		{
			pre(i);
			break;
		}
	for(int i=1;i<=n;i++)
	{
		if(siz[i]<=ans)
			continue;
		if(l[i]!=-1&&r[i]!=-1&&dfs(l[i],r[i]))
			ans=siz[i];
	}
	printf("%d",ans);
	return 0;
}