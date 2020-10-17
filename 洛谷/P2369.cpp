#include<cstdio>
#include<algorithm>
using namespace std;
int ans[800000],n,m,test,cnt,k;
int duru()
{
	int n=0;
	char x;
	x=getchar();
	while(!(x<='9'&&x>='0')) x=getchar();
	while(x>='0'&&x<='9')
	{
		n=n*10+x-'0';
		x=getchar();
	}
	return n;
}
void shuchu(int x)
{
	char ans[15];
	int i=0;
	if(!x)
		putchar('0');
	else
	{
		for(;x>0;x/=10) ans[i++]=x%10+'0';
		for(i--;i>=0;i--) putchar(ans[i]);
	}
	putchar('\n');
}
int main()
{
	n=duru();
	m=duru();
	if(n<800000)
	{
		for(k=0;k<n;k++)
			ans[k]=duru();
		sort(ans,ans+n);
		for(int k=0;k<m;k++)
			shuchu(ans[k]);
	}
	else
	{
		for(;k<800000;k++) ans[k]=duru();
		sort(ans,ans+800000);
		for(;k<n;k++)
		{
			test=duru();
			if(ans[799999-cnt]>test)
			{
    	        ans[799999-cnt]=test;
        	    cnt++;
			}
		}
		sort(ans,ans+800000);
		for(k=0;k<m;k++) shuchu(ans[k]);
	}
	return 0;
}
