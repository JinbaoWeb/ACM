#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int MAXV = 100000;
const int MAXN = 100;
#define INF 0x8f
#define MAX(a,b) a>b?a:b
int n;
int s[MAXN+5],f[MAXN+5];
int dp[MAXV*2+5];
void ZeroOnePack(){
	for (int i=0;i<=2*MAXV;i++)
		dp[i]=-INF;
	dp[MAXV]=0;
	for (int i=1;i<=n;i++){
		if(s[i]<0 && f[i]<0)
            continue;
		if (s[i]>0){
			for (int j=2*MAXV;j>=s[i];j--)
				if (dp[j-s[i]]>-INF)
					dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
		}
		else{
			for (int j=s[i];j-s[i]<=2*MAXV;j++)
				if (dp[j-s[i]]>-INF)
					dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
		}
	}
}
int main(){
	while (~scanf("%d",&n)){
		for (int i=1;i<=n;i++)
			scanf("%d%d",&s[i],&f[i]);
		ZeroOnePack();
		int ans=-INF;
        for(int i=100000;i<=200000;i++)
            if(dp[i]>=0&&dp[i]+i-100000>ans)
                ans=dp[i]+i-100000;
        printf("%d\n",ans);
	}
	return 0;
}