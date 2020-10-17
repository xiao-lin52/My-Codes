#include<cstdio>
using namespace std;
int n[3],visit[10];
bool fenjie(int a[])
{
	for(int i=0; i<3; i++)
		for(int j=1000; j>=10; j/=10)
			if(!visit[a[i]%j/(j/10)])
				visit[a[i]%j/(j/10)]=1;
			else
				return false;
	return true;
}
int main()
{
	visit[0]=1;
	for(n[0]=100; n[0]<=333; n[0]++)
	{
		n[1]=n[0]*2;
		n[2]=n[0]*3;
		if(fenjie(n)) printf("%d %d %d\n",n[0],n[1],n[2]);
		for(int i=1; i<10; i++) visit[i]=0;
	}
	return 0;
}
