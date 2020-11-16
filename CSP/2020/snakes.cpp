#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int N=1e6+10,inf=1e9;
int t,n,k,num,a[N],vis[N];
vector<int> sk;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	for(int T=1;T<=t;T++)
	{
		if(T==1)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&a[i]);
				sk.insert(lower_bound(sk.begin(),sk.end(),a[i]),a[i]);
			}
		}
		else
		{
			sk.clear();
			scanf("%d",&k);
			for(int i=1;i<=k;i++)
			{
				int p,val;
				scanf("%d%d",&p,&val);
				a[p]=val;
			}
			for(int i=1;i<=n;i++)
				sk.insert(lower_bound(sk.begin(),sk.end(),a[i]),a[i]);
		}
		num=n;
		while(num>1)
		{
			if(sk.size()==2)
			{
				sk.pop_back();
				break;
			}
			int maxn=sk[sk.size()-1],minn=sk[0],pminn=sk[1];
			if(maxn-minn<pminn)
				break;
			else
			{
				sk.erase(sk.begin());
				sk.pop_back();
				sk.insert(lower_bound(sk.begin(),sk.end(),maxn-minn),maxn-minn);
				num--;
			}
		}
		printf("%d\n",sk.size());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
