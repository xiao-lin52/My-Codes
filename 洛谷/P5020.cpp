#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[101];
int main()
{
	scanf("%d",&t);
	while(t>0)
	{
		int m,ans,opt[30000]={0};
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		m=a[n];
		ans=n;
		for(int i=1;i<=n;i++)
		{
			if(opt[a[i]])
			{
				ans--;
				continue;
			}
			for(int j=a[i];j<=m;j++)
				if(opt[j-a[i]]||j%a[i]==0)
					opt[j]=1;
		}
		printf("%d\n",ans);
		t--;
	}
	return 0;
}
