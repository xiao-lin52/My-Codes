#include<cstdio>
using namespace std;
int a,b,c,x,y,z,q;
bool check(int a,int b,int c)
{
	bool visit[10]={1};
	if(!visit[a/100])
		visit[a/100]=1;
	else
		return false;
	if(!visit[a%100/10])
		visit[a%100/10]=1;
	else
		return false;
	if(!visit[a%10])
		visit[a%10]=1;
	else
		return false;
	if(!visit[b/100])
		visit[b/100]=1;
	else
		return false;
	if(!visit[b%100/10])
		visit[b%100/10]=1;
	else
		return false;
	if(!visit[b%10])
		visit[b%10]=1;
	else
		return false;
	if(!visit[c/100])
		visit[c/100]=1;
	else
		return false;
	if(!visit[c%100/10])
		visit[c%100/10]=1;
	else
		return false;
	if(!visit[c%10])
		visit[c%10]=1;
	else
		return false;
	return true;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(x=100;x<=333;x++)
		if(x%a==0)
			if(check(x,x/a*b,x/a*c))
			{
				printf("%d %d %d\n",x,x/a*b,x/a*c);
				q=1;
			}
	if(!q)
		printf("No!!!");
	return 0;
}
