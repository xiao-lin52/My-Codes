#include<cstdio>
#include<map>
using namespace std;
int n,m,p,q,cnt1,cnt2,f[20001];
int find(int x)
{
	if(f[x]==x)
		return f[x];
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=1;i<=n+m;i++)
		f[i]=i;
	for(int i=1;i<=p;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[find(x)]=find(y);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[find(n-x)]=find(n-y);
	}
	for(int i=1;i<=n;i++)
		if(find(i)==find(1))
			cnt1++;
	for(int i=n+1;i<=n+m;i++)
		if(find(i)==find(n+1))
			cnt2++;
	printf("%d",cnt1<cnt2?cnt1:cnt2);
	return 0;
}