#include<cstdio>
#include<queue>
#define min(a,b) a<b? a:b
using namespace std;
int t,n,m,d,l,ans;
queue<int> q;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		while(q.size())
			q.pop();
		ans=0x3f3f3f3f;
		scanf("%d%d%d%d",&n,&m,&d,&l);
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			if(a<=d)
				q.push(a);
			else
			{
				while(q.size()&&a-q.front()>d)
					q.pop();
				ans=min(ans,q.size());
				q.push(a);
			}
		}
		while(q.size()&&l-q.front()>d)
			q.pop();
		ans=min(ans,q.size());
		if(ans>=m)
			printf("Excited\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}