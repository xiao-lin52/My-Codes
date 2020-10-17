#include<cstdio>
using namespace std;
int n,na,nb,pa,pb,a[210],b[210],p[5][5];
int main()
{
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=0;i<na;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<nb;i++)
		scanf("%d",&b[i]);
	p[0][0]=p[1][1]=p[2][2]=p[3][3]=p[4][4]=2;
	p[0][2]=p[0][3]=p[1][3]=p[2][4]=p[3][4]=p[1][0]=p[4][0]=p[2][1]=p[4][1]=p[3][2]=1;
	p[0][1]=p[0][4]=p[1][2]=p[1][4]=p[2][3]=p[2][0]=p[3][0]=p[3][1]=p[4][2]=p[4][3]=0;
	for(int i=0;i<n;i++)
		switch(p[a[i%na]][b[i%nb]])
		{
			case 0:
				pb++;
				break;
			case 1:
				pa++;
				break;
		}
	printf("%d %d",pa,pb);
	return 0;
}
