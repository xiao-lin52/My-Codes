#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	int r;
	char w[20];
	char t[20];
};
node tree[200001];
int n,m,mj;
char ans[20];
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		scanf("%s",tree[i].w);
		for(int j=0;j<strlen(tree[i].w);j++)
			tree[i].t[j]=towlower(tree[i].w[j]);
		return;
	}
	build(i*2,l,(l+r)/2);
	build(i*2+1,(l+r)/2+1,r);
	if(strcmp(tree[i*2].t,tree[i*2+1].t)>0)
	{
		strcpy(tree[i].w,tree[i*2].w);
		strcpy(tree[i].t,tree[i*2].t);
	}
	else
	{
		strcpy(tree[i].w,tree[i*2+1].w);
		strcpy(tree[i].t,tree[i*2+1].t);
	}
}
void query(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		if(strcmp(tree[i].t,ans)>=0)
		{
			strcpy(ans,tree[i].t);
			mj=i;
		}
		return;
	}
	if(tree[i*2].r>=l)
		query(i*2,l,r);
	if(tree[i*2+1].l<=r)
		query(i*2+1,l,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		strcpy(ans,"\0");
		mj=0;
		scanf("%d%d",&x,&y);
		query(1,x,y);
		printf("%s\n",tree[mj].w);
	}
	return 0;
}
