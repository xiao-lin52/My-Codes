#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string n,m;
int b,jw,j,x[2010],y[2010],s[2010];
int main()
{
	cin>>b>>n>>m;
	x[0]=n.length();
	y[0]=m.length();
	j=x[0]>y[0]? x[0]:y[0];
	for(int i=1;i<=x[0];i++)
		if(n[x[0]-i]>='0'&&n[x[0]-i]<='9')
			x[i]=n[x[0]-i]-'0';
		else
			x[i]=n[x[0]-i]-'A'+10;
	for(int i=1;i<=y[0];i++)
		if(m[y[0]-i]>='0'&&m[y[0]-i]<='9')
			y[i]=m[y[0]-i]-'0';
		else
			y[i]=m[y[0]-i]-'A'+10;
	for(int i=1;i<=j;i++)
	{
		s[i]=(x[i]+y[i]+jw)%b;
		jw=(x[i]+y[i]+jw)/b;
	}
	if(jw)
		s[++j]=jw;
	for(int i=j;i>0;i--)
		if(s[i]>=0&&s[i]<=9)
			printf("%d",s[i]);
		else
			printf("%c",s[i]-10+'A');
	return 0;
}
