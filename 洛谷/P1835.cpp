#include<bits/stdc++.h>
using namespace std;
int l,r,cnt,k,prime[70010],b[70010],p[2000010];
void work()
{
	int n=sqrt(r);
	for(int i=2;i<=n;i++)
	{
		if(!b[i])
			prime[++k]=i;
		for(int j=1;i*prime[j]<=n&&j<=k;j++)
		{
			b[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}
int check()
{
	for(int i=1;i<=k;i++)
		for(long long j=max(2,l/prime[i])*prime[i];j<=r;j+=prime[i])
			p[j-l+1]=1;
}
int main()
{
	scanf("%d%d",&l,&r);
	work();
	check();
	for(long long i=l;i<=r;i++)
		if(!p[i-l+1])
			cnt++;
	printf("%d",cnt);
	return 0;
}
