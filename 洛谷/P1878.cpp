#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	int l;
	int r;
};
node h[5000001];
int n,tot,sum,a[200001],v[200001],ans[200001][2];
char p[200001];
void up(int i)
{
	while(i/2>=1)
	{
		if(h[i].data<h[i/2].data||(h[i].data==h[i/2].data&&h[i].l<h[i/2].l))
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
		if((h[i].data<h[t].data||h[t].data>h[t+1].data||(h[t].data==h[t+1].data&&h[t].l>h[t+1].l))&&t+1<=tot)
			t++;
		if(h[i].data>h[t].data||(h[i].data==h[t].data&&h[i].l>h[t].l))
		{
			swap(h[i],h[t]);
			i=t;
		}
		else
			break;
	}
}
void del()
{
	swap(h[1],h[tot]);
	tot--;
	down(1);
}
void insert(int x,int l,int r)
{
	tot++;
	if(l>r)
		swap(l,r);
	h[tot].data=x;
	h[tot].l=l;
	h[tot].r=r;
	up(tot);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
		if(p[i]!=p[i-1])
			insert(abs(a[i]-a[i-1]),i-1,i);
	while(tot)
	{
		int x=h[1].l,y=h[1].r;
		del();
		if(!v[x]&&!v[y])
		{
			sum++;
			ans[sum][0]=x;
			ans[sum][1]=y;
			v[x]=v[y]=1;
			while(v[x]&&x>=1)
				x--;
			while(v[y]&&y<=n)
				y++;
			if(x>=1&&y<=n&&p[x]!=p[y])
				insert(abs(a[x]-a[y]),x,y);
		}
	}
	printf("%d",sum);
	for(int i=1;i<=sum;i++)
		printf("\n%d %d",ans[i][0],ans[i][1]);
	return 0;
}
