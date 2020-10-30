#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,head,tail,sum,p[N],t[N],v[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int op,price,ti;
		scanf("%d%d%d",&op,&price,&ti);
		if(op)
		{
			int flag=0;
			while(head<tail&&(t[head]+45<ti||v[head]))
				head++;
			for(int i=head;i<tail;i++)
				if(!v[i]&&p[i]>=price)
				{
					v[i]=flag=1;
					break;
				}
			if(!flag)
				sum+=price;
		}
		else
		{
			sum+=price;
			p[tail]=price;
			t[tail]=ti;
			tail++;
		}
	}
	printf("%d",sum);
	return 0;
}