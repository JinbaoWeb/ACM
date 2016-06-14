#include <iostream>
#include <string.h>
using namespace std;
double dp[2][5001];
int main(){
	int n,T;
	double p,t;
	cin>>n>>T;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=1;i<=n;i++){
		cin>>p>>t;
		for (int j=1;j<=i;j++){
			dp[i%2][j]=0;
			if (i-j>0)
				dp[i%2][j]+=dp[1-i%2][j]*(100-p)/100*t;
			dp[i%2][j]+=dp[1-i%2][j-1]*p/100*t;
		}
	}
	cout<<dp[n%2][n]<<endl;
	return 0;
}