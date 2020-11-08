#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,l,t,cnt,x,w,pos[N];
int main()
{
	scanf("%d%d%d",&n,&l,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&w);
		if(w==1)
		{
			cnt+=x+t>=l;
			pos[i-1]=(x+t)%l;
		}
		else
		{
			cnt-=x-t<0;
			pos[i-1]=((x-t)%l+l)%l;
		}
	}
	sort(pos,pos+n);
	for(int i=0;i<=n-1;i++)
		printf("%d\n",pos[((i+cnt)%n+n)%n]);
	return 0;
}