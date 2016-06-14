#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
double dp[2][102];
int c,n,m;
int main(){
	while (cin>>c&&c){
		cin>>n>>m;
		if (m>n || m>c || (m+n) % 2){
			cout<<"0.000"<<endl;
			continue;
		}
		if (n>1001)		//减枝
			n= n%2?1001:1000;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1.0;
		for (int i=1;i<=n;i++){
			for (int j=0;j<=i&&j<=c;j++){
				dp[i%2][j] = 0.0;
				if ((i+j)%2)	//拿奇数颗不能剩下偶数颗，拿偶数颗不能剩下奇数颗
					continue;
				if (j>0)
					dp[i%2][j]+=dp[1-i%2][j-1]*(c-j+1)*1.0/c ;
				if (j+1<=i-1)
					dp[i%2][j]+= dp[1-i%2][j+1]*(j+1)*1.0/c;
			}
		}
		cout<<fixed<<setprecision(3)<<dp[n%2][m]<<endl;
	}
	return 0;
}