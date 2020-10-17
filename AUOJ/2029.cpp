#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define min(a,b) a<b?a:b
using namespace std;
queue<int> q;
int n,m,a,ans=inf,sum,num[10001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		q.push(a);
		num[a]++;
		if(num[a]==1)
			sum++;
		while(num[q.front()]>1&&q.size())
		{
			num[q.front()]--;
			q.pop();
		}
		if(sum==m)
			ans=min(ans,q.size());
	}
	if(ans==inf)
		printf("no answer");
	else
		printf("%d",ans);
	return 0;
}

