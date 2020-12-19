#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
char a[20];
struct Hash
{
	#define SIZE 1919810
	vector< pair<string,int> > h[SIZE];
	void insert(char a[])
	{
		string t;
		int len=strlen(a),val=0;
		for(int i=0;i<len;i++)
		{
			t+=a[i];
			val=(val*26+a[i]-'0')%SIZE;
		}
		for(int i=0;i<h[val].size();i++)
			if(h[val][i].first==t)
			{
				h[val][i].second++;
				return;
			}
		h[val].push_back(make_pair(t,1));
	}
	int find(char a[])
	{
		string t;
		int len=strlen(a),val=0;
		for(int i=0;i<len;i++)
		{
			t+=a[i];
			val=(val*26+a[i]-'0')%SIZE;
		}
		for(int i=0;i<h[val].size();i++)
			if(h[val][i].first==t)
				return h[val][i].second;
		return 0;
	}
};
Hash str;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a);
		sort(a,a+strlen(a));
		ans+=1ll*str.find(a);
		printf("%lld\n",ans);
		str.insert(a);
	}
	return 0;
}