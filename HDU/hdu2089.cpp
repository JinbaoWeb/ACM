#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXN = 1000000+10;
int dp[MAXN];
bool f(int x){
	int flag=0;
	int left=0;
	while (x){
		if (left==2 && x%10==6){
			flag=1;
			break;
		}
		left=x%10;
		x/=10;
		if (left==4){
			flag=1;
			break;
		}
	}
	if (flag==1)
		return true;
	return false;
}
void init(){
	dp[0]=0;
	for (int i=1;i<MAXN-5;i++){
		dp[i]=dp[i-1];
		if (f(i)==false)
			dp[i]+=1;
	}
}
int main(){
	int a,b;
	init();
	while (cin>>a>>b){
		if (a==0 && b==0)
			break;
		cout<<dp[b]-dp[a-1]<<endl;
	}
	return 0;
}