#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string n;
float a,b,c,i;
int q,f;
float jia(int q)
{
	switch(q)
	{
		case 1:return c-b;
		case 2:return c-a;
		case 3:return a+b;
	}
}
float jian(int q)
{
	switch(q)
	{
		case 1:return b+c;
		case 2:return a-c;
		case 3:return a-b;
	}
}
float cheng(int q)
{
	switch(q)
	{
		case 1:return c/b;
		case 2:return c/a;
		case 3:return a*b;
	}
}
float chu(int q)
{
	switch(q)
	{
		case 1:return b*c;
		case 2:return a/c;
		case 3:return a/b;
	}
}
int main()
{
	getline(cin,n);
	while(i<n.length())
	{
		while(n[i]==' '&&i<n.length()) i++;
		while(n[i]!=' '&&i<n.length())
		{
			if(n[i]>='0'&&n[i]<='9')
				switch(q)
				{
					case 0:a=a*10+n[i]-'0';break;
					case 1:b=b*10+n[i]-'0';break;
					case 2:c=c*10+n[i]-'0';break;
				}
			else
			{
				if(n[i]=='?')
					switch(q)
					{
						case 0:a=-1;break;
						case 1:b=-1;break;
						case 2:c=-1;break;
					}
				if(n[i]=='+'||n[i]=='-'||n[i]=='*'||n[i]=='/')
				{
					q++;
					switch(n[i])
					{
						case '+':f=1;break;
						case '-':f=2;break;
						case '*':f=3;break;
						case '/':f=4;break;
					}
				}
				if(n[i]=='=') q++;
			}
			i++;
		}
	}
	if(a==-1)
		switch(f)
		{
			case 1:printf("%.2f",jia(1));break;
			case 2:printf("%.2f",jian(1));break;
			case 3:printf("%.2f",cheng(1));break;
			case 4:printf("%.2f",chu(1));break;
		}
	if(b==-1)
		switch(f)
		{
			case 1:printf("%.2f",jia(2));break;
			case 2:printf("%.2f",jian(2));break;
			case 3:printf("%.2f",cheng(2));break;
			case 4:printf("%.2f",chu(2));break;
		}
	if(c==-1)
		switch(f)
		{
			case 1:printf("%.2f",jia(3));break;
			case 2:printf("%.2f",jian(3));break;
			case 3:printf("%.2f",cheng(3));break;
			case 4:printf("%.2f",chu(3));break;
		}
	return 0;
}
