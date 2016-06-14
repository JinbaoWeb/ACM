#include <iostream>
#include <string.h>
using namespace std;
int l[25];
int w[25];
int dp[25][15005];
int main(){
	int c,n;
	while (cin>>c>>n){
		for (int i=0;i<c;i++)
			cin>>l[i];
		for (int i=0;i<n;i++)
			cin>>w[i];
		memset(dp,0,sizeof(dp));
		dp[0][7500]=1;
		for (int i=0;i<n;i++){
			for (int j=0;j<c;j++){
				for (int v=0;v<=15000;v++)
					if(dp[i - 1][v] != 0)
                        dp[i][l[i]*w[i] + v] += dp[i - 1][v];
			}
		}
		cout<<dp[n][15000]<<endl;
	}
	return 0;
}