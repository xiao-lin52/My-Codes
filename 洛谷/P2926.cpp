#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],b[1000001],s[1000001],p[1000001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m=max(m,a[i]);
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++)
		if(!p[a[i]])
		{
			for(int j=1;a[i]*j<=m;j++)
				s[a[i]*j]+=b[a[i]];
			p[a[i]]=1;
		}
	for(int i=1;i<=n;i++)
		printf("%d\n",s[a[i]]-1);
	return 0;
}
