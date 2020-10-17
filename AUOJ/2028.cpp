#include<bits/stdc++.h>
using namespace std;
long long n,a,k1,k2,diff1,diff2,odd[100001],even[100001];
int main()
{
	scanf("%lld",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a);
		if(a&1)
			odd[++k1]=a;
		else
			even[++k2]=a;
	}
	odd[0]=even[0]=-1;
	sort(odd+1,odd+1+k1);
	sort(even+1,even+1+k2);
	for(int i=1; i<=k1; i++)
		if(odd[i]!=odd[i-1])
			diff1++;
	for(int i=1; i<=k2; i++)
		if(even[i]!=even[i-1])
			diff2++;
	printf("%lld",diff1*(diff1-1)/2+diff2*(diff2-1)/2);
	return 0;
}

