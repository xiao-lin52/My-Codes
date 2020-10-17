#include<cstdio>
#include<algorithm>
#define inf 1e9
using namespace std;
struct Edge
{
	int u;
	int v;
	int c;
};
bool cmp(Edge a,Edge b)
{
	return a.c<b.c;
}
Edge edge[200001];
int n,m,cnt,ans,f[5001];
int find(int x)
{
	if(f[x]==x)
		return f[x];
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	if(m<n-1)
	{
		printf("orz");
		return 0;
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].c);
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int t1=find(edge[i].u),t2=find(edge[i].v);
		if(t1!=t2)
		{
			f[t1]=t2;
			ans+=edge[i].c;
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	printf("%d",ans);
	return 0;
}
