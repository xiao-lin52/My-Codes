#include<cstdio>
#include<queue>
#define max(a,b) a>b?a:b
using namespace std;
int n,m,ans,maxm,in[1001],out[1001],s[1001],t[1001],f[1001],a[1001][1001];
queue<int>q;
void topo()
{
	for(int i=1;i<=n;i++)
		if(!in[i]&&out[i])
		{
			q.push(i);
			f[i]=1;
		}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
			if(a[u][i])
			{
				in[i]--;
				if(!in[i])
				{
					f[i]=max(f[i],f[u]+1);
					q.push(i);
				}
			}
	}
	for(int i=1;i<=n;i++)
		if(!out[i])
			ans=max(ans,f[i]);
	printf("%d",ans);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int b[1001]={0};
		scanf("%d",&s[i]);
		for(int j=1;j<=s[i];j++)
		{
			scanf("%d",&t[j]);
			b[t[j]]=1;
		}
		for(int j=1;j<=s[i];j++)
			for(int k=t[1];k<=t[s[i]];k++)
				if(!b[k]&&!a[t[j]][k])
				{
					a[t[j]][k]=1;
					in[k]++;
					out[t[j]]++;
				}
	}
	topo();
	return 0;
}