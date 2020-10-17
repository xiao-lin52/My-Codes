#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,k,l,d,x1,y1,x2,y2,i,j,maxn,maxi,a[1000],b[1000],c[1000],h[1000];
int main()
{
	scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
	for(i=1;i<=d;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)
			a[min(y1,y2)]++;
		else
			h[min(x1,x2)]++;
	}
	for(i=1;i<=k;i++)
	{
		maxn=-1;
		for(j=1;j<m;j++)
			if(h[j]>maxn)
			{
				maxn=h[j];
				maxi=j;
			}
		b[i]=maxi;
		h[maxi]=0;
	}
	for(i=1;i<=l;i++)
	{
		maxn=-1;
		for(j=1;j<n;j++)
			if(a[j]>maxn)
			{
				maxn=a[j];
				maxi=j;
			}
		c[i]=maxi;
		a[maxi]=0;
	}
	sort(b+1,b+1+k);
	sort(c+1,c+1+l);
	for(i=1;i<=k;i++)
		printf("%d ",b[i]);
	printf("\n");
	for(i=1;i<=l;i++)
		printf("%d ",c[i]);
	return 0;
}
