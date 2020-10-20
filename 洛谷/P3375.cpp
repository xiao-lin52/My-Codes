#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
char t[N],p[N];
int len1,len2,next[N];
int main()
{
	scanf("%s%s",t+1,p+1);
	len1=strlen(t+1);
	len2=strlen(p+1);
	for(int i=2,j=0;i<=len2;i++)
	{
		while(j&&p[i]!=p[j+1])
			j=next[j];
		if(p[i]==p[j+1])
			j++;
		next[i]=j;
	}
	for(int i=1,j=0;i<=len1;i++)
	{
		while(j&&t[i]!=p[j+1])
			j=next[j];
		if(t[i]==p[j+1])
			j++;
		if(j==len2)
		{
			printf("%d\n",i-len2+1);
			j=next[j];
		}
	}
	for(int i=1;i<=len2;i++)
		printf("%d ",next[i]);
	return 0;
}
