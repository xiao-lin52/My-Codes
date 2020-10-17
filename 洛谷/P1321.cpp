#include<cstdio>
#include<cstring>
using namespace std;
int s1,s2,len;
char a[256];
int main()
{
	scanf("%s",a);
	len=strlen(a);
	for(int i=0;i<len-2;i++)
		if(a[i]=='b'&&a[i+1]=='o'&&a[i+2]=='y')
		{
			s1++;
			a[i]=a[i+1]=a[i+2]='.';
		}
	for(int i=0;i<len-1;i++)
		if((a[i]=='b'&&a[i+1]=='o')||(a[i]=='o'&&a[i+1]=='y'))
		{
			s1++;
			a[i]=a[i+1]='.';
		}
	for(int i=0;i<len;i++)
		if(a[i]=='b'||a[i]=='o'||a[i]=='y')
		{
			s1++;
			a[i]='.';
		}
	printf("%d\n",s1);
	for(int i=0;i<len-3;i++)
		if(a[i]=='g'&&a[i+1]=='i'&&a[i+2]=='r'&&a[i+3]=='l')
		{
			s2++;
			a[i]=a[i+1]=a[i+2]=a[i+3]='.';
		}
	for(int i=0;i<len-2;i++)
		if((a[i]=='g'&&a[i+1]=='i'&&a[i+2]=='r')||(a[i]=='i'&&a[i+1]=='r'&&a[i+2]=='l'))
		{
			s2++;
			a[i]=a[i+1]=a[i+2]='.';
		}
	for(int i=0;i<len-1;i++)
		if((a[i]=='g'&&a[i+1]=='i')||(a[i]=='i'&&a[i+1]=='r')||(a[i]=='r'&&a[i+1]=='l'))
		{
			s2++;
			a[i]=a[i+1]='.';
		}
	for(int i=0;i<len;i++)
		if(a[i]=='g'||a[i]=='i'||a[i]=='r'||a[i]=='l')
		{
			s2++;
			a[i]='.';
		}
	printf("%d",s2);
	return 0;
}
