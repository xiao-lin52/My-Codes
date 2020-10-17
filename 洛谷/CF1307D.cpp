#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll ans,sum[26][26],suf[100010][26];
string a;
int main()
{
	getline(cin,a);
	for(int i=a.size();i>=1;i--)
		for(int j=0;j<=25;j++)
			if(a[i-1]-'a'==j)
				suf[i][j]=suf[i+1][j]+1;
			else
				suf[i][j]=suf[i+1][j];
	for(int i=0;i<=25;i++)
		ans=max(ans,suf[1][i]);
	for(int i=1;i<=a.size();i++)
		for(int j=0;j<=25;j++)
		{
			sum[a[i-1]-'a'][j]+=suf[i+1][j];
			ans=max(ans,sum[a[i-1]-'a'][j]);
		}
	printf("%lld",ans);
	return 0;
}
