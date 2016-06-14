#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1000000+10;
int a[MAXN];
int dp[MAXN];
int main(){
	int n,x;
	while (cin>>n){
		memset(dp,0,sizeof(dp));
		for (int i=1;i<MAXN;i++)
			dp[i]=1;
		//printf("----\n");
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
			for (int j=2;j*a[i]<MAXN;j++){
				//printf("%d\n",j*a[i]);
				dp[j*a[i]]=max(dp[j*a[i]],dp[a[i]]+1);
				//printf("%d %d\n",j*a[i],dp[j*a[i]] );
			}
		}
		//for (int i=0;i<n;i++){
		//	printf("%d ",dp[a[i]] );
		//}
		//printf("-----------\n");
		int Max=0;
		for (int i=0;i<n;i++){
			if (Max<dp[a[i]])
				Max=dp[a[i]];
		}
		printf("%d\n",Max );
	}
	return 0;
}