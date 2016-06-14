#include <iostream>
#include <string.h>
using namespace std;
#define MAX 5000+1
int n;
char s[MAX];
int dp[2][MAX+1];

int max(int a,int b){
	return a>b?a:b;
}
void solve(){
	for (int i=0;i<n;i++){
		dp[0][i]=0;
		dp[1][i]=0;
	}
	for (int i=0;i<n;i++) 
		for (int j=0;j<n;j++){
			if (s[i]==s[n-1-j])
				dp[(i+1)%2][j+1]=dp[i%2][j]+1;
			else
				dp[(i+1)%2][j+1]=max(dp[i%2][j+1],dp[(i+1)%2][j]);
		}
	cout<<n-dp[n%2][n]<<endl;
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
