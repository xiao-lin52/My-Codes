#include<cstdio>
#include<algorithm>
using namespace std;
struct file
{
	int w;
	int v;
};
bool cmp(file a,file b)
{
	if(a.w!=b.w) return a.w<b.w;
	if(a.v!=b.v) return a.v>b.v;
}
file a[1001];
int n,p,s,q,l,opt[1001];
int main()
{
	scanf("%d%d%d",&n,&p,&s);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].w,&a[i].v);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=s;j>=a[i].w;j--)
			opt[j]=max(opt[j],opt[j-a[i].w]+a[i].v);
		if(opt[s]>=p)
		{
			q=1;
			l=a[i].w;
			break;
		}
	}
	if(q)
		printf("%d",l);
	else
		printf("No Solution!");
	return 0;
}
