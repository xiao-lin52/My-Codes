#include<bits/stdc++.h>
using namespace std;
inline int count(int x)
{
	int sum=0;
	for(;x;x-=x&(-x))
		sum++;
	return sum;
}
int n,m,ans,sum[2000],a[110],sta[2000],t[2000][2000],dp[2000][2000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m-1;j++)
		{
			char t;
			cin>>t;
			if(t=='P')
				a[i]|=(1<<j);
		}
	if(n>=1)
		for(int i=0;i<=(1<<m)-1;i++)
		{
			sum[i]=count(i);
			if(!((i<<1)&i)&&!((i<<2)&i))
			{
				ans=max(ans,sum[i]);
				sta[i]=1;
			}
		}
	if(n>=2)
		for(int i=0;i<=(1<<m)-1;i++)
			for(int j=0;j<=(1<<m)-1;j++)
				if(sta[i]&&sta[j]&&(i&a[1])==i&&(j&a[2])==j&&!(i&j))
				{
					dp[i][j]=sum[i]+sum[j];
					ans=max(ans,dp[i][j]);
				}
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<=(1<<m)-1;j++)
			if(sta[j]&&(j&a[i-2])==j)
				for(int k=0;k<=(1<<m)-1;k++)
					if(sta[k]&&(k&a[i-1])==k&&!(j&k))
						for(int l=0;l<=(1<<m)-1;l++)
							if(sta[l]&&(l&a[i])==l&&!(j&l)&&!(k&l))
								t[k][l]=max(t[k][l],sum[l]+dp[j][k]);
		for(int j=0;j<=(1<<m)-1;j++)
			for(int k=0;k<=(1<<m)-1;k++)
			{
				dp[j][k]=t[j][k];
				ans=max(ans,dp[j][k]);
			}
	}
	cout<<ans;
	return 0;
}