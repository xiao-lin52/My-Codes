#include<bits/stdc++.h>
#define ll int
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll n,ans,len,cnt[10][10];
string a;
int main()
{
	n=read();
	while(n--)
	{
		ans=0;
		memset(cnt,0,sizeof(cnt));
		getline(cin,a);
		len=a.size();
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
			{
				for(int k=0;k<len;k++)
					if((cnt[i][j]%2==0&&a[k]-'0'==i)||(cnt[i][j]%2==1&&a[k]-'0'==j))
						cnt[i][j]++;
				if(i!=j&&cnt[i][j]%2!=0)
					cnt[i][j]--;
				ans=max(ans,cnt[i][j]);
			}
		printf("%d\n",len-ans);
	}
	return 0;
}
