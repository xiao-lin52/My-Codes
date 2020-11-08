#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,a[4];
int main()
{
	scanf("%lld",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld%lld",&a[0],&a[1],&a[2],&a[3]);
		sort(a,a+4);
		if(a[0]+a[3]!=a[1]+a[2])
			printf("0\n");
		else
			if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
				printf("1\n");
			else
				if(a[0]==a[1])
					printf("4\n");
				else
					if(a[1]==a[2])
						printf("2\n");
					else
						printf("8\n");
	}
	return 0;
}