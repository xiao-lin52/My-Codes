#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string s;
int n,q,len,tid,ans,x[N],p[N];
stack<int> num;
stack< vector<int> > val;
vector<int> k;
void solve()
{
	for(int i=0;i<len;i++)
	{
		if(s[i]==' ')
		{
			if(tid)
			{
				num.push(x[tid]);
				vector<int> tmp;
				tmp.push_back(tid);
				val.push(tmp);
			}
			tid=0;
		}
		else
		{
			if(s[i]=='x')
				tid=0;
			if(s[i]>='0'&&s[i]<='9')
				tid=tid*10+s[i]-'0';
			if(s[i]=='|')
			{
				int x1=num.top();
				num.pop();
				int x2=num.top();
				num.pop();
				num.push(x1|x2);
				vector<int> t1,t2,empty;
				t1.assign(val.top().begin(),val.top().end());
				val.pop();
				t2.assign(val.top().begin(),val.top().end());
				val.pop();
				if(!x1&&!x2)
					t1.insert(t1.end(),t2.begin(),t2.end());
				if(!x1&&x2)
					swap(t1,t2);
				if(!x1||!x2)
					val.push(t1);
				else
					val.push(empty);
			}
			if(s[i]=='&')
			{
				int x1=num.top();
				num.pop();
				int x2=num.top();
				num.pop();
				num.push(x1&x2);
				vector<int> t1,t2,empty;
				t1.assign(val.top().begin(),val.top().end());
				val.pop();
				t2.assign(val.top().begin(),val.top().end());
				val.pop();
				if(x1&&x2)
					t1.insert(t1.end(),t2.begin(),t2.end());
				if(x1&&!x2)
					swap(t1,t2);
				if(x1||x2)
					val.push(t1);
				else
					val.push(empty);
			}
			if(s[i]=='!')
			{
				int x1=num.top();
				num.pop();
				num.push(!x1);
			}
		}
	}
	ans=num.top();
	k.assign(val.top().begin(),val.top().end());
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	len=s.size();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	solve();
	sort(k.begin(),k.end());
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int j;
		scanf("%d",&j);
		int t=lower_bound(k.begin(),k.end(),j)-k.begin();
		if(t<k.size()&&k[t]==j)
			printf("%d\n",ans^1);
		else
			printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
