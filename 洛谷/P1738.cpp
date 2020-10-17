#include<cstdio>
#include<string>
#include<iostream>
#define us unsigned short
using namespace std;
struct tree
{
	string data;
	us s;
	us c[1001];
};
int n,k,ans;
string path;
tree a[50001];
int main()
{
	cin>>n;
	a[0].data="";
	for(int i=1;i<=n;i++)
	{
		us p=0,j=1;
		cin>>path;
		while(j<path.length())
		{
			if(path[path.length()-1]=='/')
				path+=" ";
			string name="";
			while(path[j]!='/'&&j<path.length())
			{
				name+=path[j];
				j++;
			}
			int flag=0;
			for(int i=1;i<=a[p].s;i++)
			{
				if(a[a[p].c[i]].data==name)
				{
					flag=i;
					break;
				}
			}
			if(!flag)
			{
				k++;
				a[p].s++;
				flag=a[p].s;
				a[k].data=name;
				a[p].c[a[p].s]=k;
			}
			p=a[p].c[flag];
			j++;
		}
		cout<<k<<endl;
	}
	return 0;
}
