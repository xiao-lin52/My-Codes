#include<cstdio>
using namespace std;
int s1,s2,s3,ans,mj,cnt[100];
int main()
{
	scanf("%d%d%d",&s1,&s2,&s3);
	for(int i=1;i<=s1;i++)
		for(int j=1;j<=s2;j++)
			for(int k=1;k<=s3;k++)
				cnt[i+j+k]++;
	for(int i=1;i<=s1+s2+s3;i++)
		if(ans<cnt[i])
		{
			ans=cnt[i];
			mj=i;
		}
	printf("%d",mj);
	return 0;
}
