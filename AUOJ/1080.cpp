#include<bits/stdc++.h>
using namespace std;
int n,m,word[1010],b[10]={1};
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&word[i]);
	for(int i=1;i<=8;i++)
		b[i]=b[i-1]*10;
	sort(word+1,word+1+n);
	for(int i=1;i<=m;i++)
	{
		int len,t,flag=1;
		scanf("%d%d",&len,&t);
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=len-1;k++)
			{
				if(t%b[k+1]/b[k]!=word[j]%b[k+1]/b[k])
					goto l;
			}
			flag=0;
			printf("%d\n",word[j]);
			break;
			l:;
		}
		if(flag)
			printf("-1\n");
	}
	return 0;
}