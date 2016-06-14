/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-10 23:49
 * Filename :        201505102349.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
using namespace std;
#define min(a,b) a<b?a:b
int dp[15][15];
int a[15][15];
int main(){
	int m,n;
	while (cin>>m>>n){
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				cin>>a[i][j];
		dp[0][0]=a[0][0];
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (i-1>=0 && j-1>=0)
					dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
				else if (i-1>=0)
					dp[i][j]=dp[i-1][j]+a[i][j];
				else if (j-1>=0)
					dp[i][j]=dp[i][j-1]+a[i][j];
			}
		}
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}
		cout<<dp[m-1][n-1]<<endl;
	}

	return 0;
}
