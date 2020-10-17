#include<cstdio>
#include<algorithm>
using namespace std;
struct man
{
	int s;
	int w;
	int index;
};
bool cmp(man a,man b)
{
	if(a.s!=b.s) return a.s>b.s;
	return a.index<b.index;
}
man a[200010],win[100001],fail[100001],f[200010]={0};
int n,r,q,ans;
int main()
{
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i].s);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d",&a[i].w);
		a[i].index=i;
	}
	sort(a+1,a+1+2*n,cmp);
	for(int i=1;i<=r;i++)
	{
		int top1=0,top2=0,t1=1,t2=1,t3=1;
		for(int j=1;j<=2*n;j+=2)
		{
			if(a[j].w<a[j+1].w)
			{
				a[j+1].s++;
				win[++top1]=a[j+1];
				fail[++top2]=a[j];
			}
			else
			{
				a[j].s++;
				win[++top1]=a[j];
				fail[++top2]=a[j+1];
			}
		}
		while(t1<=n&&t2<=n)
		{
			if(cmp(win[t1],fail[t2]))
			{
				f[t3]=win[t1];
				t1++;
				t3++;
			}
			else
			{
				f[t3]=fail[t2];
				t2++;
				t3++;
			}
		}
		while(t1<=n)
		{
			f[t3]=win[t1];
			t1++;
			t3++;
		}
		while(t2<=n)
		{
			f[t3]=fail[t2];
			t2++;
			t3++;
		}
		for(int j=1;j<=2*n;j++)
			a[j]=f[j];
	}
	printf("%d",a[q].index);
	return 0;
}
