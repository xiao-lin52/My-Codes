#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,r,y,m,d,num[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&q);
	while(q--)
	{
		y=4713;
		m=1;
		scanf("%lld",&r);
		if(r<=1721424)
		{
			y-=r/1461*4;
			r%=1461;
			m=1;
			while(r>=(y%4==1? 366 : 365))
			{
				r-=(y%4==1? 366 : 365);
				y--;
			}
			while(r>=(y%4==1? (m==2 ? 29 : 28 ) : num[m]))
			{
				r-=(y%4==1? (m==2 ? 29 : 28 ) : num[m]);
				m++;
			}
			d=1+r;
			printf("%lld %lld %lld BC\n",d,m,y);
		}
		if(r>1721424&&r<=2299160)
		{
			r-=1721424;
			y=r/1461*4+1;
			r%=1461;
			m=1;
			while(r>=(y%4==0? 366 : 365))
			{
				r-=(y%4==0? 366 : 365);
				y++;
			}
			while(r>=(y%4==0? (m==2 ? 29 : num[m] ) : num[m]))
			{
				r-=(y%4==0? (m==2 ? 29 : num[m] ) : num[m]);
				m++;
			}
			d=1+r;
			printf("%lld %lld %lld\n",d,m,y);
		}
		if(r>2299160)
		{
			r-=2299160;
			if(r<=88)
			{
				if(r<=27)
					printf("%lld 10 1582\n",r+14);
				if(27<r&&r<=57)
					printf("%lld 11 1582\n",r-27);
				if(57<r&&r<=88)
					printf("%lld 12 1582\n",r-57);
			}
			else
			{
				r-=88;
				y=r/146096*400+1583;
				r%=146096;
				m=1;
				while(r>=((y%400==0||(y%4==0&&y%100!=0)) ? 366 : 365))
				{
					r-=((y%400==0||(y%4==0&&y%100!=0)) ? 366 : 365);
					y++;
				}
				while(r>=(m==2?((y%400==0||(y%4==0&&y%100!=0))?29:28):num[m]))
				{
					r-=(m==2?((y%400==0||(y%4==0&&y%100!=0))?29:28):num[m]);
					m++;
				}
				d=1+r;
				printf("%lld %lld %lld\n",d,m,y);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
