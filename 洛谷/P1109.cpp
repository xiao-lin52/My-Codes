#include<cstdio>
#include<algorithm>
using namespace std;
int n,r,l,t,w,s,ans,a[50];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	scanf("%d%d",&l,&r);
	if(s<l*n||s>r*n)
		printf("-1");
	else
	{
		s=0;
		w=n-1;
		sort(a,a+n);
		while(a[t]<l) t++;
		while(a[w]>r) w--;
		for(int i=0;i<t;i++)
			ans+=l-a[i];
		for(int i=n-1;i>w;i--)
			s+=a[i]-r;
		ans=max(ans,s);
		printf("%d",ans);
	}
	return 0;
}
