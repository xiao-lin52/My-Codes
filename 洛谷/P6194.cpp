#include<bits/stdc++.h>
using namespace std;
char a[11][11];
int ans[11][11];
int main()
{
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!='.')
				ans[i][j]=1;
		}
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=8;j++)
		{
			if(a[i][j]=='B')
			{
				for(int k=1;k<i&&k<j;k++)
					if(a[i-k][j-k]=='.')
						ans[i-k][j-k]=1;
					else
						break;
				for(int k=1;k<8-i+1&&k<j;k++)
					if(a[i+k][j-k]=='.')
						ans[i+k][j-k]=1;
					else
						break;
				for(int k=1;k<i&&k<8-j+1;k++)
					if(a[i-k][j+k]=='.')
						ans[i-k][j+k]=1;
					else
						break;
				for(int k=1;k<8-i+1&&k<8-j+1;k++)
					if(a[i+k][j+k]=='.')
						ans[i+k][j+k]=1;
					else
						break;
			}
			if(a[i][j]=='R')
			{
				for(int k=1;k<i;k++)
					if(a[i-k][j]=='.')
						ans[i-k][j]=1;
					else
						break;
				for(int k=1;k<8-i+1;k++)
					if(a[i+k][j]=='.')
						ans[i+k][j]=1;
					else
						break;
				for(int k=1;k<j;k++)
					if(a[i][j-k]=='.')
						ans[i][j-k]=1;
					else
						break;
				for(int k=1;k<8-j+1;k++)
					if(a[i][j+k]=='.')
						ans[i][j+k]=1;
					else
						break;
			}
		}
	}
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=8;j++)
			printf("%d",ans[i][j]^1);
		printf("\n");
	}
	return 0;
}
