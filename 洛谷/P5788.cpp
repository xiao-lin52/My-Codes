#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
int n,a[N],f[N];
stack<int> st;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		while(st.size()&&a[st.top()]<a[i])
		{
			f[st.top()]=i;
			st.pop();
		}
		st.push(i);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",f[i]);
	return 0;
}