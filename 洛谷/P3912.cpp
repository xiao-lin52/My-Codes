#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,cnt,k,prime[N];
bool b[N*100];
void work()
{
	for(int i=2;i<=n/2;i++)
	{
		if(!b[i])
			prime[++k]=i;
		for(int j=1;j<=k&&i*prime[j]<=n;j++)
		{
			b[i*prime[j]]=1;
			cnt--;
			if(i%prime[j]==0)
				break;
		}
	}
}
int main()
{
	scanf("%d",&n);
	cnt=n-1;
	work();
	printf("%d",cnt);
	return 0;
}
