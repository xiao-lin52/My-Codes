#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct ticket
{
	int t1;
	int p1;
	int v;
};
ticket a[100010];
int n,q,p,t,s=0,head=0,tail=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&q,&p,&t);
		if(q==0)
		{
			a[tail].t1=t;
			a[tail].p1=p;
			tail++;
			s+=p;
		}
		else
		{
			while((a[head].t1+45<t||a[head].v==1)&&head<tail)
				head++;
			int flag=0;
			for(int j=head;j<tail;j++)
				if(a[j].p1>=p&&!a[j].v)
				{
					flag=1;
					a[j].v=1;
					break;
				}
			if(!flag)
				s+=p;
		}
	}
	printf("%d",s);
	return 0;
}
