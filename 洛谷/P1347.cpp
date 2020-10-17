#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m,flag,a[31][31],in[31],out[31],ans[31];
void topo()
{
	int s=0,tot=0,f[31]={0};
	queue<int> q;
	memcpy(f,in,sizeof(in));
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
		if(f[i]||out[i])
		{
			s++;
			if(!f[i])
				q.push(i);
		}
	while(q.size())
	{
		if(q.size()>1)
			flag=1;
		int u=q.front();
		q.pop();
		ans[++tot]=u;
		for(int i=1;i<=n;i++)
		{
			if(a[u][i])
			{
				f[i]--;
				if(!f[i])
					q.push(i);
			}
		}
	}
	if(tot<s)
	{
		flag=2;
		return;
	}
	if(flag)
		return;
	if(tot==n)
	{
		flag=3;
		return;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
//		if(i==30)
//		{
//			int fuck=0;
//			fuck++;
//			fuck--;
//		}
		char t1,t2,t3;
		int x,y,f1,f2;
		cin>>t1>>t2>>t3;
		x=t1-'A'+1;
		y=t3-'A'+1;
		if(x==y)
		{
			cout<<"Inconsistency found after "<<i<<" relations.";
			goto l;
		}
		if(!a[x][y])
		{
			a[x][y]=1;
			in[y]++;
			out[x]++;
		}
		flag=0;
//		if(i==30)
		topo();
		switch(flag)
		{
			case 2:
				cout<<"Inconsistency found after "<<i<<" relations.";
				goto l;
			case 3:
				cout<<"Sorted sequence determined after "<<i<<" relations: ";
				for(int i=1;i<=n;i++)
					cout<<char(ans[i]+'A'-1);
				cout<<".";
				goto l;
		}
	}
	cout<<"Sorted sequence cannot be determined.";
	l:;
	return 0;
}
