/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-11 19:05
 * Filename :        poj3176.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int a[352][352];
int dp[352][352];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	while (~scanf("%d",&n)){
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++)
			for (int j=1;j<=i;j++)
				scanf("%d",&a[i][j]);
		for (int i=1;i<=n;i++)
			dp[n][i]=a[n][i];
		for (int i=n-1;i>0;i--){
			for (int j=1;j<=i;j++){
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
			}
		}
		printf("%d\n",dp[1][1]);
	}
	return 0;
}
