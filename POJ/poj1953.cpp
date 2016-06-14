#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
ll dp[1000];
int main(){
	int n,t;
	dp[1]=2;
	dp[2]=3;
	for (int i=3;i<51;i++)
		dp[i]=dp[i-1]+dp[i-2];
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>n;
		cout<<"Scenario #"<<i+1<<":"<<endl;
		cout<<dp[n]<<endl<<endl;
	}
	return 0;
}
