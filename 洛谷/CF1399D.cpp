#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,k,a,b[200010];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		k=0;
		queue<int> q0,q1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%1d",&a);
			if(a)
				if(q0.size())
				{
					q1.push(b[i]=q0.front());
					q0.pop();
				}
				else
					q1.push(b[i]=++k);
			else
				if(q1.size())
				{
					q0.push(b[i]=q1.front());
					q1.pop();
				}
				else
					q0.push(b[i]=++k);
		}
		printf("%d\n",k);
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}
