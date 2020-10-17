#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int s,h,t,a[241],ans[241];
string cnm;
int main()
{
	cin>>cnm;
	for(int i=0;i<cnm.length();i++)
		a[i+1]=cnm[i]-'0';
	scanf("%d",&s);
	h=1;
	t=s+1;
	for(int i=1;i<=cnm.length()-s;i++)
	{
		int shit=10,mj;
		for(int j=h;j<=t;j++)
			if(shit>a[j])
			{
				shit=a[j];
				mj=j;
			}
		ans[i]=shit;
		h=mj+1;
		t++;
	}
	int laomu=1;
	while(ans[laomu]==0)
		laomu++;
	if(laomu>cnm.length()-s) laomu=cnm.length()-s;
	for(int i=laomu;i<=cnm.length()-s;i++)
		printf("%d",ans[i]);
	return 0;
}
