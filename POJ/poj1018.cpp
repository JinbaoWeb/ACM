/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-18 13:47
 * Filename :        poj1018.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 1005;
int t,n,m,k;
int B[MAX],P[MAX];
int dp[MAX][MAX];
int max;
void input(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		k=1;
		max=0;
		while (n--){
			scanf("%d",&m);
			while (m--){
				scanf("%d%d",&B[k++],&P[k++]);
				if (B[k-1]>max)
					max=B[k-1];
			}
		}
	}
}
void solve(){
	memset(dp,0xffff,sizeof(dp));
	
	for (int j=0;j<max;j++){
		for (int i=0;i<k;i++){
			if (dp[i][j]+P[j])
		}
	}
}
int main(){

	return 0;
}
