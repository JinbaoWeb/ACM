/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-05 23:30
 * Filename :        301D.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
double dp[101][101][101];
int main(){
	int r,s,p;
	while (~scanf("%d%d%d",&r,&s,&p)){
		dp[r][s][p]=1;
		for (int i=r;i>=0;i--){
			for (int j=s;j>=0;j--){
				for (int k=p;k>=0;k--){
					int sum=(i+j+k)*(i+j+k-1)/2-i*(i-1)/2-j*(j-1)/2-k*(k-1)/2;
					if (i>0&&j>0)
						dp[i][j-1][k]+=dp[i][j][k]*i*j/sum;
					if (i>0&&k>0)
						dp[i-1][j][k]+=dp[i][j][k]*i*k/sum;
					if (j>0&&k>0)
						dp[i][j][k-1]+=dp[i][j][k]*j*k/sum;
				}
			}
		}
		double ans_r=0,ans_s=0,ans_p=0;
		for (int i=r;i>=0;i--)
			ans_r+=dp[i][0][0];
		for (int j=s;j>=0;j--)
			ans_s+=dp[0][j][0];
		for (int k=p;k>=0;k--)
			ans_p+=dp[0][0][k];
		printf("%.10f %.10f %.10f\n",ans_r,ans_s,ans_p);
	}

	return 0;
}
