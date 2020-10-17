#include<cstdio>
using namespace std;
int n,t,ans,t1,t2;
int main()
{
	scanf("%d%d",&n,&t);
	scanf("%d",&t1);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d",&t2);
		if(t2-t1<t)
			ans+=t2-t1;
		else
			ans+=t;
		t1=t2;
	}
	printf("%d",ans+t);
	return 0;
}
