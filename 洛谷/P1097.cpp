#include<cstdio>
#include<algorithm>
using namespace std;
int s,n,i,a[200000];
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=1;i<n;i++)
		if(a[i]==a[i-1])
			s++;
		else
		{
			s++;
			printf("%d %d\n",a[i-1],s);
			s=0;
		}
	s++;
	printf("%d %d",a[i-1],s);
	return 0;
}
