#include<iostream>

#include<queue>

#include<cstring>

using namespace std;

struct Edge

{

	int next;

	int to;

	int w;

};

int change(char x)

{

	if(x>='A'&&x<='Z')

		return x-'A'+1;

	if(x>='a'&&x<='z')

		return x-'a'+27;

}

Edge edge[20001];

int n,cnt,head[61],dis[61];

queue<int>q;

void add_edge(int u,int v,int c)

{

	cnt++;

	edge[cnt].next=head[u];

	edge[cnt].to=v;

	edge[cnt].w=c;

	head[u]=cnt;

}

int main()

{

	memset(dis,0x3f3f3f,sizeof(dis));

	cin>>n;

	for(int i=1;i<=n;i++)

	{

		char u,v;

		int t1,t2,c;

		cin>>u>>v>>c;

		t1=change(u);

		t2=change(v);

		add_edge(t1,t2,c);

		add_edge(t2,t1,c);

	}

	q.push(26);

	dis[26]=0;

	while(!q.empty())

	{

		int u=q.front();

		for(int i=head[u];i;i=edge[i].next)

		{

			int v=edge[i].to;

			if(dis[v]>dis[u]+edge[i].w)

			{

				dis[v]=dis[u]+edge[i].w;

				q.push(v);

			}

		}

		q.pop();

	}

	int mj=0,ans=1000000000;

	for(int i=1;i<=25;i++)

		if(ans>dis[i])

		{

			ans=dis[i];

			mj=i;

		}

	cout<<char(mj+'A'-1)<<" "<<ans;

	return 0;

}
