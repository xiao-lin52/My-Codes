#include<string>
#include<iostream>
using namespace std;
int n,q;
string qwq,abcd,ans[101][2];
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>ans[i][0]>>ans[i][1];
	for(int i=1;i<=q;i++)
	{
		cin>>qwq;
		for(int j=1;j<=n;j++)
		{
			if(ans[j][0]==qwq)
			{
				for(int k=1;k<=4;k++)
				{
					cin>>qwq;
					if(qwq==ans[j][1])
						cout<<char(k-1+'A')<<endl;
				}
				break;
			}
		}
	}
	return 0;
}
