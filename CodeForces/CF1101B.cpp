#include<cstdio>
#include<cstring>
using namespace std;
char a[500001];
int i,j,k,l,ans;
int main()
{
	scanf("%s",a);
	i=0;
	j=strlen(a)-1;
	while(a[i]!='['&&i<j)
		i++;
	while(a[j]!=']'&&i<j)
		j--;
	if(i>=j)
	{
		printf("-1");
		return 0;
	}
	k=i+1;
	l=j-1;
	while(a[k]!=':'&&k<l)
		k++;
	while(a[l]!=':'&&k<l)
		l--;
	if(k>=l)
	{
		printf("-1");
		return 0;
	}
	for(int c=k+1;c<=l-1;c++)
		if(a[c]=='|')
			ans++;
	printf("%d",ans+4);
	return 0;
}
