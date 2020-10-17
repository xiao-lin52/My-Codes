#include<cstdio>
using namespace std;
int a,sum,visit[42];
int main()
{
	for(int i=1;i<=10;i++)
	{
		scanf("%d",&a);
		if(!visit[a%42])
		{
			sum++;
			visit[a%42]=1;
		}
	}
	printf("%d",sum);
	return 0;
}
