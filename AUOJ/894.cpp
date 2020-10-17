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
ll n,t,a,x,y,dir,ax,ay,adir;
int main()
{
	n=read();t=read();
	for(int i=0;i<=n-1;i++)
	{
		a=read();
		switch(dir)
		{
			case 0:
				x+=a;
				break;
			case 1:
				y+=a;
				break;
			case 2:
				x-=a;
				break;
			case 3:
				y-=a;
				break;
		}
		dir=(dir+a)%4;
	}
	for(int i=1;i<=t;i++)
	{
		switch(adir)
		{
			case 0:
				ax+=x;
				ay+=y;
				break;
			case 1:
				ax+=y;
				ay-=x;
				break;
			case 2:
				ax-=x;
				ay-=y;
				break;
			case 3:
				ax-=y;
				ay+=x;
				break;
		}
		adir=(adir+dir)%4;
	}
	ax=ax<0?-ax:ax;
	ay=ay<0?-ay:ay;
	printf("%lld",ax+ay);
	return 0;
}

