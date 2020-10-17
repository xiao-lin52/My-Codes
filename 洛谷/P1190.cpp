#include<cstdio>
using namespace std;
int w[10000],a,n,i,t,s,x;
int  main()
{
	scanf("%d%d",&n,&s);
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	x=s;
	while(s<=n)
	{
		a=100;
		for(i=0;i<x;i++)
			if(w[i]<a&&w[i]!=0)
				a=w[i];
		for(i=0;i<x;i++)
		{
			if(w[i]==a)
			{
				w[i]=w[s];
				w[s]=0;
				s++;
			}
			else
				w[i]-=a;
		}
		t+=a;
	}
	for(i=a=0;i<x;i++)
		if(w[i]>a)
			a=w[i];
	t+=a;
	printf("%d",t);
	return 0;
}
