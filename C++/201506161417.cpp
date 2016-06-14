#include <iostream>
using namespace std;
const int MAX = 105;
int n;
int a[MAX],b[MAX];
int dp[MAX][MAX];
int solve(){
	for (int i=0;i<=n;i++)
		dp[0][i]=dp[i][0]=0;
	for (int i=1;i<=n;i++){
		int sum_a=0,sum_b=0;
		for (int j=1;j<=i;j++){
			dp[i][j]=dp[i-1][j];
			if (sum_a+a[j]>=0 && sum_b+b[j]>=0 && dp[i-1][j-1]+a[j]+b[j]>dp[i][j]){
				sum_a+=a[j];
				sum_b+=b[j];
				dp[i][j]=dp[i-1][j-1]+a[j]+b[j];
			}
		}
	}
	return dp[n][n];
}
void debug(){
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}
int main(){
	while (cin>>n){
		for (int i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		cout<<solve()<<endl;
		debug();
	}
	return 0;
}