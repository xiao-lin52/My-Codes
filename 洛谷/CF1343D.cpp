#include<bits/stdc++.h>
#define N 200010
using namespace std;
int t,n,k,mn=0x3f3f3f3f,ans,sum,a[N],b[N<<1];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		mn=0x3f3f3f3f;
		memset(b,0,sizeof(b));
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n/2;i++)
		{
			b[min(a[i],a[n-i+1])+1]++;
			b[a[i]+a[n-i+1]]--;
			b[a[i]+a[n-i+1]+1]++;
			b[max(a[i],a[n-i+1])+k+1]--;
			b[2]+=2;
			b[min(a[i],a[n-i+1])+1]-=2;
			b[max(a[i],a[n-i+1])+k+1]+=2;
			b[2*k+1]-=2;
		}
		for(int i=2;i<=2*k;i++)
		{
			sum+=b[i];
			if(mn>sum)
			{
				mn=sum;
				ans=i;
			}
		}
		printf("%d\n",mn);
	}
	return 0;
}
