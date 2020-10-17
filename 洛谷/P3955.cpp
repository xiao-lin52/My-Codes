#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000],b[1000],c,h,i,j,k,n,q,s[1000],v,mod[9]={0,10,100,1000,10000,100000,1000000,10000000,100000000};
int main()
{
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=0;i<q;i++)
		scanf("%d%d",&s[i],&b[i]);
	for(i=0;i<q;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]%mod[s[i]]==b[i])
			{
				v=1;
				printf("%d\n",a[j]);
				break;
			}
			c=0;
		}
		if(v==0) printf("-1\n");
		v=c=0;
	}
	return 0;
}
