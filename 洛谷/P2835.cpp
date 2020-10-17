#include<cstdio>
#include<algorithm>
using namespace std;
struct Count
{
	int cnt;
	int p;
};
bool cmp(Count a,Count b)
{
	return a.cnt>b.cnt;
}
Count s[201];
int n,ans,dis[201][201],v[201];
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int a;
		s[i].p=i;
		scanf("%d",&a);
		while(a)
		{
			dis[i][a]=1;
			scanf("%d",&a);
		}
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dis[i][j]=dis[i][j]|(dis[i][k]&dis[k][j]);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i!=j)
				s[i].cnt+=dis[i][j];
	sort(s+1,s+1+n,cmp);
	for(int i=1; i<=n; i++)
	{
		if(v[s[i].p])
			continue;
		ans++;
		for(int j=1; j<=n; j++)
			v[j]=v[j]|dis[s[i].p][j];
		v[s[i].p]=1;
	}
	printf("%d",ans);
	return 0;
}
