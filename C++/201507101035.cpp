#include <iostream>
using namespace std;
const int MAXN = 45;
const int MAXM = (1<<20);
int a[MAXN];
int dp[MAXN][MAXM];
int main(){
	int t,m,n;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		//dp[i][j]=dp[i-1][j]+dp[i-1][j^a[i]]
		dp[0][0]=1;
		for (int i=1;i<=)

	}
	return 0;
}