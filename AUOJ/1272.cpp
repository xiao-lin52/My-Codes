#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const ll N=2e3+10,mod=1e9+7;
struct ZJK_AK_IOI
{
	int l;
	int r;
	int p;
};
bool cmp1(ZJK_AK_IOI a,ZJK_AK_IOI b)
{
	return a.l==b.l ? a.r<b.r : a.l<b.l;
}
bool cmp2(ZJK_AK_IOI a,ZJK_AK_IOI b)
{
	return a.p==b.p ? (a.l==b.l ? a.r<b.r : a.l<b.l) : a.p<b.p;
}
ZJK_AK_IOI a[N];
int n,m,now,flag;
ll t=1,ans,dp[N][N][4];
/*
dp[][][0]: 1,5,7
dp[][][1]: 2,4,8
dp[][][2]: 3,9
dp[][][3]: 0,6
*/
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+1+m,cmp1);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i!=j&&a[i].l>=a[j].l&&a[i].r<=a[j].r)
				a[j].p=1;
	sort(a+1,a+1+m,cmp2);
	for(int i=m;i>=1;i--)
		if(a[i].p)
			m--;
		else
			break;
	for(int i=1;i<=m;i++)
	{
		dp[i][a[i].l][0]=dp[i][a[i].l][1]=3;
		dp[i][a[i].l][2]=dp[i][a[i].l][3]=2;
		for(int j=a[i].l+1;j<=a[i].r;j++)
		{
			dp[i][j][0]=dp[i][j-1][0]*3%mod;
			dp[i][j][1]=((dp[i][j-1][0]+dp[i][j-1][1])*3%mod+dp[i][j-1][1]*3%mod)%mod;
			dp[i][j][2]=((dp[i][j-1][0]+dp[i][j-1][2])*2%mod+dp[i][j-1][2]*3%mod)%mod;
			dp[i][j][3]=((dp[i][j-1][0]+dp[i][j-1][1]+dp[i][j-1][2])*2%mod+dp[i][j-1][3]*10%mod+dp[i][j-1][2]*3%mod+dp[i][j-1][1]*2%mod)%mod;
		}
		// if(a[i-1].r>=a[i].l)
		// 	ans=(ans*)%mod
	}
	return 0;
}