#include<iostream>
#include<string>
using namespace std;
int v,i,q,a[4];
string n;
int main()
{
	cin>>n;
	while(i<n.length())
	{
		if(q)
		{
			if(n[i]>='0'&&n[i]<='9')
			{
				int temp=0;
				while(n[i]>='0'&&n[i]<='9')
				{
					temp=temp*10+n[i]-'0';
					i++;
				}
				a[v]=temp;
			}
			else
			{
				switch(n[i])
				{
					case 'a':
						a[v]=a[1];
						break;
					case 'b':
						a[v]=a[2];
						break;
					case 'c':
						a[v]=a[3];
						break;
				}
			}
		}
		switch(n[i])
		{
			case 'a':
				v=1;
				break;
			case 'b':
				v=2;
				break;
			case 'c':
				v=3;
				break;
			case '=':
				q=1;
				break;
			case ';':
				q=0;
				break;
		}
		i++;
	}
	cout<<a[1]<<' '<<a[2]<<' '<<a[3];
	return 0;
}
