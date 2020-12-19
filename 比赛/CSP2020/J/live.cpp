#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,w,a[N];
vector<int> num;
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		int t=max(1,i*w/100)-1;
		scanf("%d",&a[i]);
		num.insert(lower_bound(num.begin(),num.end(),a[i]),a[i]);
		printf("%d ",num[num.size()-1-t]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
