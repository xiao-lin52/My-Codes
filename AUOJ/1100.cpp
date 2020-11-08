#include<bits/stdc++.h>
using namespace std;
int t,n,k,mn,mx;
char a[20];
void dfs(int x,int step,int num)
{
	if(x>n)
	{
		mn=min(mn,num);
		mx=max(mx,num);
		return;
	}
	dfs(x+1,step,num*10+a[x]-'0');
	if(step<k)
		for(int j=x+1;j<=n;j++)
			if(x!=1||a[j]!='0')
			{
				swap(a[x],a[j]);
				dfs(x+1,step+1,num*10+a[x]-'0');
				swap(a[x],a[j]);
			}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",a+1,&k);
		n=strlen(a+1);
		mn=1000000010;
		mx=0;
		dfs(1,0,0);
		printf("%d\n",mx-mn);
	}
	return 0;
}
