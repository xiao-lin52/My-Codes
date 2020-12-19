#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,base1=101,base2=131,mod1=19260817,mod2=1000000007;
int get(char x)
{
	if(x>='0'&&x<='9')
		return x-'0';
	if(x>='a'&&x<='z')
		return x-'a'+10;
	return x-'A'+36;
}
int hash1(char a[])
{
	int val=0,len=strlen(a+1);
	for(int i=1;i<=len;i++)
		val=(val*base1%mod1+get(a[i]))%mod1;
	return val;
}
int hash2(char a[])
{
	int val=0,len=strlen(a+1);
	for(int i=1;i<=len;i++)
		val=(val*base2%mod2+get(a[i]))%mod2;
	return val;
}
int n,sum;
char a[N];
set< pair<int,int> > str;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a+1);
		str.insert(make_pair(hash1(a),hash2(a)));
	}
	printf("%d",str.size());
	return 0;
}