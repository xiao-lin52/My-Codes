#include<iostream>

#include<string>

#define max(a,b) a>b?a:b

using namespace std;

int maxn,cnt[27];

string a;

int main()

{

	for(int i=1;i<=4;i++)

	{

		getline(cin,a);

		for(int j=0;j<a.length();j++)

			if(a[j]>='A'&&a[j]<='Z')

			{

				cnt[a[j]-'A'+1]++;

				maxn=max(maxn,cnt[a[j]-'A'+1]);

			}

	}

	for(int i=maxn;i>=1;i--)

		for(int j=1;j<=26;j++)

		{

			if(cnt[j]>=i)

				cout<<"*";

			else

				cout<<" ";

			if(j==26)

				cout<<"\n";

			else

				cout<<" ";

		}

	for(int i=1;i<=26;i++)

	{

		cout<<char(i+'A'-1);

		if(i<=25)

			cout<<" ";

	}

	return 0;

}
