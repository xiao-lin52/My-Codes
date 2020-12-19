#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,nxt[N];
char a[N];
int main()
{
	scanf("%d%s",&n,a+1);
	for(int i=2,j=0;i<=n;i++)
	{
		while(a[i]!=a[j+1]&&j)
			j=nxt[j];
		if(a[i]==a[j+1])
			j++;
		nxt[i]=j;
	}
	printf("%d",n-nxt[n]);
	return 0;
}