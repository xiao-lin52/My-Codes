#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110;
int n,k,p[N],q[N],s[N],t[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&q[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
		t[q[i]]=p[i];
	if(!memcmp(t,s,sizeof(t))&&k!=1)
	{
		for(int i=1;i<=n;i++)
			t[i]=p[q[i]];
		if(!memcmp(t,s,sizeof(t)))
		{
			printf("NO");
			return 0;
		}
	}
	if(!memcmp(p,s,sizeof(p)))
	{
		printf("NO");
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
			t[q[j]]=p[j];
		for(int j=1;j<=n;j++)
			p[j]=t[j];
		if(!memcmp(p,s,sizeof(p)))
		{
			if((k-i)%2==0)
			{
				printf("YES");
				return 0;
			}
			break;
		}
	}
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
			t[j]=p[q[j]];
		for(int j=1;j<=n;j++)
			p[j]=t[j];
		if(!memcmp(p,s,sizeof(p)))
		{
			if((k-i)%2==0)
			{
				printf("YES");
				return 0;
			}
			break;
		}
	}
	printf("NO");
	return 0;
}