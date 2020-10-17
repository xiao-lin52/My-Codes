#include<bits/stdc++.h>
using namespace std;
struct node
{
	int w;
	int id;
};
bool cmp(node a,node b)
{
	if(a.w!=b.w)
		return a.w<b.w;
	else
		return a.id<b.id;
}
node a[100001];
int n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].w);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		ans=max(ans,a[i].id-i);
	printf("%d",ans+1);
	return 0;
}
