#include<bits/stdc++.h>
using namespace std;
int n,op,tot,x,h[1000001];
void up(int i)
{
	int t;
	while(i/2>=1)
	{
		t=i/2;
		if(h[i]<h[t])
		{
			swap(h[i],h[i/2]);
			i/=2;
		}
		else
			break;
	}
}
void down(int i)
{
	int t;
	while(i*2<=tot)
	{
		t=i*2;
		if((h[i]<h[t]||h[t]>h[t+1])&&t+1<=tot)
			t++;
		if(h[i]>h[t]&&t<=tot)
		{
			swap(h[i],h[t]);
			i=t;
		}
		else
			break;
	}
}
void insert(int x)
{
	h[++tot]=x;
	up(tot);
}
void del(int i)
{
	swap(h[i],h[tot]);
	tot--;
	up(i);
	down(i);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				scanf("%d",&x);
				insert(x);
				break;
			case 2:
				printf("%d\n",h[1]);
				break;
			case 3:
				del(1);
		}
	}
	return 0;
}
