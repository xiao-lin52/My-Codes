#include<bits/stdc++.h>
using namespace std;
priority_queue< int,vector<int>,less<int> > a;
priority_queue< int,vector<int>,greater<int> > b;
int n,x;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(a.size()&&x<=a.top())
			a.push(x);
		else
			b.push(x);
		while(a.size()<i/2)
		{
			a.push(b.top());
			b.pop();
		}
		while(a.size()>i/2)
		{
			b.push(a.top());
			a.pop();
		}
		if(i%2==1)
			printf("%d\n",b.top());
	}
	return 0;
}
