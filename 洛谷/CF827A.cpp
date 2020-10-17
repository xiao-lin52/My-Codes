#include<bits/stdc++.h>
using namespace std;
int n,k,x,m,a[10000001];
string t[1000001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>k;
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			if(t[a[x]].length()<t[i].length())
				a[x]=i;
			m=max(m,x);
		}
	}
	int i=1;
	while(i<=m)
	{
		if(!a[i])
			printf("a");
		else
		{
			int j;
			for(j=0;j<t[a[i]].length();j++)
			{
				if(t[a[i+j]].length()+j>t[a[i]].length())
					break;
				else
					printf("%c",t[a[i]][j]);
			}
			i+=j;
			continue;
		}
		i++;
	}
	return 0;
}
