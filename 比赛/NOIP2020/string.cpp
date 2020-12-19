//求神 ZJK 保佑我这道题不要挂分
//求神 LSJ 保佑我这道题不要挂分
//求神 WKR 保佑我这道题不要挂分
//求神 MZX 保佑我这道题不要挂分
//求神 XFY 保佑我这道题不要挂分
#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const long long N=(1ll<<20)+10;
long long n,ans,flag,len,cnt[100],pre[N],suf[N],tree[100];
char str[N];
void update(long long x,long long k)
{
	for(;x<=27;x+=lowbit(x))
		tree[x]+=k;
}
long long query(long long x)
{
	long long sum=0;
	for(;x>=1;x-=lowbit(x))
		sum+=tree[x];
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--)
	{
		ans=0;
		flag=0;
		memset(cnt,0,sizeof(cnt));
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
		memset(str,0,sizeof(str));
		memset(tree,0,sizeof(tree));
		scanf("%s",str+1);
		len=strlen(str+1);
		for(long long i=1;i<=len;i++)
		{
			cnt[str[i]-'a'+1]++;
			if(cnt[str[i]-'a'+1]%2==1)
				pre[i]=pre[i-1]+1;
			else
				pre[i]=pre[i-1]-1;
		}
		memset(cnt,0,sizeof(cnt));
		for(long long i=len;i>=1;i--)
		{
			cnt[str[i]-'a'+1]++;
			if(cnt[str[i]-'a'+1]%2==1)
				suf[i]=suf[i+1]+1;
			else
				suf[i]=suf[i+1]-1;
		}
		for(int i=1;i<=26;i++)
			if(cnt[i]==len)
				flag=1;
		if(!flag)
			for(long long j=1;j<len;j++)//枚举ab 
			{
				if(j!=1)
					for(long long i=j;i<len;i++)//枚举(ab)^i 
					{
						if(str[i]!=str[(i-1)%j+1])
							break;
						if(i%j==0)
							ans+=query(suf[i+1]+1);
					}
				update(pre[j]+1,1);
			}
		else
			for(long long j=1;j<len;j++)//枚举ab 
			{
				if(j!=1)
					for(long long i=1;i*j<len;i++)//枚举(ab)^i 
					{
						ans+=query(suf[i*j+1]+1);
					}
				update(pre[j]+1,1);
			}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
log:
O(n^3)的瓶颈在于枚举对于每一个合法的ab，有多少a是合法的
试对其进行预处理
草，不行，预处理变成O(n^3)的了 
等等，枚举(ab)^i的时候实际上F(c)已经定了，最后一层貌似可以拿个数据结构维护一下？ 
行了，拿了个树状数组搞上去，现在是O(n^2logn)了，不过常数有点大，因为还判断了ab能否是(ab)^i
这样大致能拿个48pts 
现在瓶颈在于枚举ab，判断ab是否能构成合法的(ab)^i 
这怕是只能预处理了 
只剩1个半小时左右了，先去打了T4暴力再回来看看
还剩1h15min，得加油了，争取做出这道题
现在想一下为什么要枚举ab
废话，因为题面说也要统计(ab)^i这种啊，你枚举了(ab)^i怎么能不枚举ab啊
那能不能优化这个过程呢。。。 
见鬼，树状数组优化和这个优化冲突了 
又改了一下，现在是小常数O(n^2logn)了，48pts问题不大了 
要是能O(1)比较两个字符串就还能优化成近似于O(nlog^2n)，但这玩意总不能字符串哈希吧。。。 
不行，字符串哈希连样例都过不去
只有25min了，我人没了。。。
估个分好了，100+48+10+15=173pts，后两题还是乐观估计的，有可能还要低。。。 
明年再来好了，我还是太菜了，现在就是希望前两题不要挂分，否则就真GG了 
mdCCF，wtcl，wssb，要AFO了。。。 
*/
