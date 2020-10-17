#include<bits/stdc++.h>
using namespace std;
int n,block,a[50001],bl[50001],L[501],R[501],add[501];
void update(int l,int r,int k)
{
	if(bl[l]==bl[r])
	{
		for(int i=L[bl[l]];i<=R[bl[l]];i++)
			a[i]+=add[bl[l]];
		for(int i=l;i<=r;i++)
			a[i]+=k;
	}
	else
	{
		for(int i=bl[l]+1;i<=bl[r]-1;i++)
			add[i]+=k;
		for(int i=L[bl[l]];i<=R[bl[l]];i++)
			a[i]+=add[bl[l]];
		for(int i=L[bl[r]];i<=R[bl[r]];i++)
			a[i]+=add[bl[r]];
		for(int i=l;i<=R[bl[l]];i++)
			a[i]+=k;
		for(int i=L[bl[r]];i<=r;i++)
			a[i]+=k;
	}
	add[bl[l]]=add[bl[r]]=0;
}
int query(int x)
{
	for(int i=L[bl[x]];i<=R[bl[x]];i++)
		a[i]+=add[bl[x]];
	add[bl[x]]=0;
	return a[x];
}
int main()
{
	scanf("%d",&n);
	block=sqrt(n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=block;i++)
	{
		L[i]=(i-1)*block+1;
		R[i]=i*block;
	}
	if(R[block]<n)
	{
		block++;
		L[block]=R[block-1]+1;
		R[block]=n;
	}
	for(int i=1;i<=block;i++)
		for(int j=L[i];j<=R[i];j++)
			bl[j]=i;
	for(int i=1;i<=n;i++)
	{
		int op,l,r,c;
		scanf("%d%d%d%d",&op,&l,&r,&c);
		if(!op)
			update(l,r,c);
		else
			printf("%d\n",query(r));
	}
	return 0;
}
