#include<bits/stdc++.h>
using namespace std;
int n,tot;
long long ans,a[20001];
void up(int i)
{
	while(i/2>=1)
		if(a[i]<a[i/2])
		{
			swap(a[i],a[i/2]);
			i/=2;
		}
		else
			break;
}
void down(int i)
{
	int t;
	while(i*2<=tot)
	{
		t=i*2;
		if((a[i]<a[t]||a[t]>a[t+1])&&t+1<=tot)
			t++;
		if(a[i]>a[t])
		{
			swap(a[i],a[t]);
			i=t;
		}
		else
		{
			break;
		}
		
	}
}
void del()
{
	swap(a[1],a[tot]);
	tot--;
	down(1);
}
void insert(int x)
{
	a[++tot]=x;
	up(tot);
}
void makeheap()
{
	for(int i=tot/2;i>=1;i--)
		down(i);
}
int main()
{
	scanf("%d",&n);
	tot=n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	makeheap();
	for(int i=1;i<=n-1;i++)
	{
		del();
		del();
		ans+=a[tot+1]+a[tot+2];
		insert(a[tot+1]+a[tot+2]);
	}
	printf("%lld",ans);
	return 0;
}
