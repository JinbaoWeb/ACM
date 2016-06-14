#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
const int MOD = 530600414;
LL ans[300000],pos[300000],cnt[300000],len[300000];
void init()
{
	memset(ans,0,sizeof(ans));
	memset(pos,0,sizeof(pos));
	memset(cnt,0,sizeof(cnt));
	pos[3]=1;pos[4]=3;
	ans[3]=0;ans[4]=0;
	cnt[3]=1;cnt[4]=1;
	len[3]=3;len[4]=5;
	for (int i=5;i<=201314;i++)
	{
		ans[i]=ans[i-2]+ans[i-1]-pos[i-2]*cnt[i-1]%MOD+(cnt[i-1]*len[i-2]%MOD+pos[i-1])*cnt[i-2]%MOD;
		while(ans[i]<0) ans[i]+=MOD;
		ans[i]%=MOD;
		pos[i]=(pos[i-2]+pos[i-1]+cnt[i-1]*len[i-2])%MOD;
		cnt[i]=(cnt[i-1]+cnt[i-2])%MOD;
		len[i]=(len[i-1]+len[i-2])%MOD;
	}
}
int main(int argc, char const *argv[])
{
	init();
	int t;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		int n;
		scanf("%d",&n);
		printf("Case #%d: %I64d\n",TT,ans[n] );
	}
	return 0;
}