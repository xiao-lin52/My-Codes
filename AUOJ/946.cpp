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
ll n;
int main()
{
	n=read();
	printf("%lld",2*n);
	return 0;
}
