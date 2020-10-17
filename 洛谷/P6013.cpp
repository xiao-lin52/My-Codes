#include<cstdio>
using namespace std;
int n,op,k,ans;
long long sum,f[1000001];
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int a,b;
			sum+=f[i];
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				scanf("%d",&a);
				sum+=a;
				break;
			case 2:
				scanf("%d",&a);
				if(sum>=a)
					sum-=a;
				else
					ans++;
				break;
			case 3:
				scanf("%d%d",&a,&b);
				//if(b<=i)
					//break;
				sum-=a;
				f[b]+=a;
				break;
		}
	}
	printf("%d",ans);
	return 0;
}
