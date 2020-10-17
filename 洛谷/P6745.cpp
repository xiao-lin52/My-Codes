#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,x,cnt;
void cal(ll a)
{
	while(a/10)
	{
		cnt++;
		a/=10;
	}
	cnt++;
}
ll ksm(ll a,ll b)
{
	ll ans=1;
	for(int i=1;i<=b;i++)
		ans*=a;
	return ans;
}
int main()
{
	cin>>k>>x;
	cal(x);
	if(cnt<k)
	{
		cout<<"1";
		for(int i=1;i<=k-cnt;i++)
			cout<<"0";
		cout<<x;
	}
	else
		cout<<x+ksm(10,k);
	return 0;
}
