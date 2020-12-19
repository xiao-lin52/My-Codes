#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
char s[N],t[N];
int len1,len2,ans,nxt[N];
int main()
{
	scanf("%s%s",s+1,t+1);
	len1=strlen(s+1);
	len2=strlen(t+1);
	for(int i=2,j=0;i<=len2;i++)
	{
		while(t[i]!=t[j+1]&&j)
			j=nxt[j];
		if(t[i]==t[j+1])
			j++;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=len1;i++)
	{
		while(s[i]!=t[j+1]&&j)
			j=nxt[j];
		if(s[i]==t[j+1])
			j++;
		if(j==len2)
		{
			ans++;
			j=0;
		}
	}
	printf("%d",ans);
	return 0;
}