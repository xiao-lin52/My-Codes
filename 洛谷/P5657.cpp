#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,k;
string ans;
void solve(ll x,ll k)
{
	if(x==1)
	{
		ans+=(char)k+'0';
		return;
	}
	if(k<(1ull<<(x-1)))
	{
		solve(x-1,k);
		ans+='0';
	}
	else
	{
		solve(x-1,(1ull<<(x-1))-1+(1ull<<(x-1))-k);
		ans+='1';
	}
}
int main()
{
	cin>>n>>k;
	solve(n,k);
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}