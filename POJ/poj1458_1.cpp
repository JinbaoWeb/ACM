#include <iostream>
#include <string.h>
using namespace std;
char a[1000],b[1000];
int dp[1000][1000];
int max(int a,int b){
	return a>b?a:b;
}
int LCS(char *a,char *b){
	int n=strlen(a),m=strlen(b);
	for (int i=0;i<n;i++)
		dp[i][0]=0;
	for (int j=0;j<m;j++)
		dp[0][j]=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			if (a[i]==b[j])
				dp[i+1][j+1]=dp[i][j]+1;
			else
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		}
	return dp[n][m];
}
int main(){
	while (cin>>a>>b){
		cout<<LCS(a,b)<<endl;
	}
	return 0;
} 
