#include<cstdio>
using namespace std;
int n,ans;
char a[100];
int main()
{
	scanf("%d%s",&n,a);
	for(int j=0; j<n-1; j++)
		if(a[j]=='V'&&a[j+1]=='K')
		{
			ans++;
			a[j]=a[j+1]=' ';
		}
	for(int j=0; j<n-1; j++)
		if((a[j]=='V'&&a[j+1]=='V')||(a[j]=='K'&&a[j+1]=='K'))
		{
			ans++;
			break;
		}
	printf("%d",ans);
	return 0;
}
