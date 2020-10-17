#include<string>
#include<iostream>
using namespace std;
string a,ans,num[10],n[21]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
int k,j;
int main()
{
	cin>>a;
	while(a!=".")
	{
		for(int i=1;i<=20;i++)
			if(n[i]==a)
			{
				k++;
				num[k]+=i*i%100/10+'0';
				num[k]+=i*i%100%10+'0';
				break;
			}
		if(a=="a"||a=="another"||a=="first")
			num[++k]="01";
		if(a=="both"||a=="second")
			num[++k]="04";
		if(a=="third")
			num[++k]="09";
		cin>>a;
	}
	for(int i=1;i<=k;i++)
	{
		for(int l=i+1;l<=k;l++)
			if(num[i]>num[l])
			{
				string t=num[i];
				num[i]=num[l];
				num[l]=t;
			}
		ans+=num[i];
	}
	while(ans[j]=='0')
		j++;
	for(int i=j;i<k*2;i++)
		cout<<ans[i];
	if(k==0)
		cout<<"0";
	return 0;
}
