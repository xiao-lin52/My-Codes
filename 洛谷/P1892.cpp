#include<cstdio>
#include<iostream>
using namespace std;
int n,m,ans,f[2001],b[2001];
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
	for(int i=1;i<=2*n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
        char p;
		cin>>p>>x>>y;
		if(p=='E')
		{
			f[find(x)]=find(y+n);
			f[find(x+n)]=find(y);
		}
		else
		{
			f[find(x)]=find(y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int t=find(i);
		if(!b[t])
		{
			b[t]=1;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}