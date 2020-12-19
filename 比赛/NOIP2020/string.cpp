//���� ZJK ����������ⲻҪ�ҷ�
//���� LSJ ����������ⲻҪ�ҷ�
//���� WKR ����������ⲻҪ�ҷ�
//���� MZX ����������ⲻҪ�ҷ�
//���� XFY ����������ⲻҪ�ҷ�
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
			for(long long j=1;j<len;j++)//ö��ab 
			{
				if(j!=1)
					for(long long i=j;i<len;i++)//ö��(ab)^i 
					{
						if(str[i]!=str[(i-1)%j+1])
							break;
						if(i%j==0)
							ans+=query(suf[i+1]+1);
					}
				update(pre[j]+1,1);
			}
		else
			for(long long j=1;j<len;j++)//ö��ab 
			{
				if(j!=1)
					for(long long i=1;i*j<len;i++)//ö��(ab)^i 
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
O(n^3)��ƿ������ö�ٶ���ÿһ���Ϸ���ab���ж���a�ǺϷ���
�Զ������Ԥ����
�ݣ����У�Ԥ������O(n^3)���� 
�ȵȣ�ö��(ab)^i��ʱ��ʵ����F(c)�Ѿ����ˣ����һ��ò�ƿ����ø����ݽṹά��һ�£� 
���ˣ����˸���״�������ȥ��������O(n^2logn)�ˣ����������е����Ϊ���ж���ab�ܷ���(ab)^i
�����������ø�48pts 
����ƿ������ö��ab���ж�ab�Ƿ��ܹ��ɺϷ���(ab)^i 
������ֻ��Ԥ������ 
ֻʣ1����Сʱ�����ˣ���ȥ����T4�����ٻ�������
��ʣ1h15min���ü����ˣ���ȡ���������
������һ��ΪʲôҪö��ab
�ϻ�����Ϊ����˵ҲҪͳ��(ab)^i���ְ�����ö����(ab)^i��ô�ܲ�ö��ab��
���ܲ����Ż���������ء����� 
������״�����Ż�������Ż���ͻ�� 
�ָ���һ�£�������С����O(n^2logn)�ˣ�48pts���ⲻ���� 
Ҫ����O(1)�Ƚ������ַ����ͻ����Ż��ɽ�����O(nlog^2n)�����������ܲ����ַ�����ϣ�ɡ����� 
���У��ַ�����ϣ������������ȥ
ֻ��25min�ˣ�����û�ˡ�����
�����ֺ��ˣ�100+48+10+15=173pts�������⻹���ֹ۹��Ƶģ��п��ܻ�Ҫ�͡����� 
�����������ˣ��һ���̫���ˣ����ھ���ϣ��ǰ���ⲻҪ�ҷ֣��������GG�� 
mdCCF��wtcl��wssb��ҪAFO�ˡ����� 
*/
