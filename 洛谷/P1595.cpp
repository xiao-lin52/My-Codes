#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	register long long x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
long long n,f[21];
int main()
{
	f[1]=0;
	f[2]=1;
	n=read();
	for(int i=3;i<=n;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	printf("%lld",f[n]);
	return 0;
}
