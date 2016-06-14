#include <iostream>
#include <string.h>
using namespace std;
#define MAX 5000+1
int n;
char s[MAX];
int dp[MAX+1][MAX+1];

int max(int a,int b){
	return a>b?a:b;
}
void solve(){
	dp[0][0]=(s[0]==s[n-1]);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			if (s[i]==s[n-1-j])
				dp[(i+1)][j+1]=dp[i][j]+1;
			else
				dp[(i+1)][j+1]=max(dp[i][j+1],dp[(i+1)][j]);
		}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<n-dp[n][n]<<endl;
}
int main(){
	
	while (cin>>n){
		for (int i=0;i<n;i++){
			cin>>s[i];
		}
		solve();
	}
	return 0;
}
