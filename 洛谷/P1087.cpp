#include<cstdio>

#include<cstring>

using namespace std;

int n;

char a[1024];

char check(int i,int j)

{

	int s0=0,s1=0;

	while(i<=j)

	{

		if(a[i]=='0')

			s0++;

		else

			s1++;

		i++;

	}

	if(s0==0)

		return 'I';

	if(s1==0)

		return 'B';

	return 'F';

}

void FBI(int i,int j)

{

	if(i<j)

	{

		FBI(i,(i+j-1)/2);

		FBI((i+j+1)/2,j);

	}

	printf("%c",check(i,j));

}

int main()

{

	scanf("%d%s",&n,a);

	FBI(0,strlen(a)-1);

	return 0;

}
