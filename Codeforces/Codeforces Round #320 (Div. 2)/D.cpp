#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll dp[200010][15];
ll a[200010];
ll f(int x,int s){
	ll ans=1;
	for (int i=1;i<=s;i++){
		ans*=x;
	}
}
int main(){
	int n,k,x;
	while (cin>>n>>k>>x){
		for (int i=0;i<n;i++)
			cin>>a[i];
		dp[0][0]=a[0];
		for (int i=1;i<=k;i++){
			dp[0][i]=a[0]*pow(x,i);
			//cout<<f(x,i)<<" "<<dp[0][i]<<endl;
		}
		for (int i=1;i<n;i++){
			for (int j=0;j<=k;j++){
				dp[i][j]=0;
				for (int s=0;s<=j;s++){
					//cout<<i-1<<" "<<j-s<<" "<<dp[i-1][j-s]<<" "<<((a[i])*f(x,s))<<endl;
					ll tmp=(a[i])*pow(x,s);
					dp[i][j]=max(dp[i][j],dp[i-1][j-s]|tmp);
				}
				//cout<<dp[i][j]<<endl;
			}
		}
		ll ans=-1;
		for (int i=0;i<=k;i++){
			//cout<<dp[n-1][i]<<endl;
			if (ans<dp[n-1][i])
				ans=dp[n-1][i];
		}
		cout<<ans<<endl;
	}
	return 0;
}