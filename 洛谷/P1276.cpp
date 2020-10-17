#include<bits/stdc++.h>
using namespace std;
int l,n,ans1,ans2,a[10005];
int main()
{
	scanf("%d%d",&l,&n);
	for(int i=0;i<=l;i++)
		a[i]=2;
	for(int i=1;i<=n;i++)
	{
		int op,u,v;
		scanf("%d%d%d",&op,&u,&v);
		if(!op)
			for(int j=u;j<=v;j++)
			{
				if(a[j]==1)
					ans2++;
				a[j]=0;
			}
		else
			for(int j=u;j<=v;j++)
				if(!a[j])
					a[j]=1;
	}
	for(int i=0;i<=l;i++)
		if(a[i]==1)
			ans1++;
	printf("%d\n%d",ans1,ans2);
	return 0;
}
