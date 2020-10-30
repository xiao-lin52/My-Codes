#include<bits/stdc++.h>
using namespace std;
inline int count(int x)
{
	int s=0;
	for(;x;x-=(x&(-x)))
		s++;
	return s;
}
long long n,m,ans,sta[2000],sum[2000],dp[10][2000][100];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<=(1<<n)-1;i++)
	{
		if(!(i&(i<<1)))
			sta[i]=1;
		sum[i]=count(i);
		dp[1][i][sum[i]]=1;
	}
	for(int i=2;i<=n;i++)
		for(int j=0;j<=(1<<n)-1;j++)
			if(sta[j])
				for(int k=0;k<=(1<<n)-1;k++)
					if(sta[k]&&!(j&(k<<1))&&!(j&k)&&!(j&(k>>1)))
						for(int l=sum[k];l<=m;l++)
							dp[i][k][l]+=dp[i-1][j][l-sum[k]];
	for(int i=0;i<=(1<<n)-1;i++)
		ans+=dp[n][i][m];
	printf("%lld",ans);
	return 0;
}