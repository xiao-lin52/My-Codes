#include<cstdio>
#include<algorithm>
using namespace std;
struct Edge
{
	int u;
	int v;
	int c;
};
Edge edge[100001];
int n,m,k,s,ans,f[100001];
bool cmp(Edge a,Edge b)
{
	return a.c>b.c;
}
int find(int x)
{
	if(f[x]==x)
		return f[x];
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].c);
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;s<k;i++)
	{
		int t1=find(edge[i].u),t2=find(edge[i].v);
		if(t1!=t2)
		{
			ans+=edge[i].c;
			s++;
			f[t1]=f[t2];
		}
	}
	printf("%d",ans);
	return 0;
}