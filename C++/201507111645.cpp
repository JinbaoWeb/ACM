#include <iostream>
#include <stdio.h>
using namespace std;
int dp[500+5];
int sum[100000+5];
int num[100000+5];
int a[100000+5];
int C[100000+5];
int W[100000+5];
int ZeroOnePack(int N,int K){
    for (int i=0;i<=K;i++)
        dp[i]=0;
    for (int i=0;i<N;i++)
        for (int j=K;j>=C[i];j--)
            dp[j]=min(dp[j],dp[j-C[i]]+W[i]);
    return dp[K];
}
int main(){
	int t,n,m,k;
	int x,y,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&m);
		sum[0]=num[0]=0;
		long long ans=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			ans+=a[i];
			num[i]=num[i-1];
			sum[i]=sum[i-1];
			if (a[i]<0){
				num[i]++;
				sum[i]+=a[i];
			}
		}
		for (int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&c);
			C[i]=c*(num[y]-num[x]+1);
			W[i]=sum[y]-sum[x-1];
		}
		printf("%lld\n",ans-ZeroOnePack(n,k));
	}

	return 0;
}