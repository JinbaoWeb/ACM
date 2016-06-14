#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define inf 0xffffff
int n,a[10][10],sum[10][10];
int dp[15][10][10][10][10];
int countsum(int x1,int y1,int x2,int y2){
	return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}
int fun(int k){
	//初始化
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++)
			for (int k=0;k<8;k++)
				for (int s=0;s<8;s++){
					int t=countsum(i,j,k,s);
					dp[0][i][j][k][s]=t*t;
				}	
	for (int a=1;a<=k;a++){	
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				for (int k=0;k<8;k++){
					for (int s=0;s<8;s++){
						int minmin = inf;
						if ((k-i+1)*(s-j+1)<a+1){
							dp[a][i][j][k][s]=minmin;
							continue;
						}
						for (int m=i;m<k;m++){
							int t=countsum(m+1,j,k,s);
							int t2=countsum(i,j,m,s);
							minmin=min(minmin,min(dp[a-1][i][j][m][s]+t*t,dp[a-1][m+1][j][k][s]+t2*t2));
						}
						for (int m=j;m<s;m++){
							int t=countsum(i,m+1,k,s);
							int t2=countsum(i,j,k,m);
							minmin=min(minmin,min(dp[a-1][i][j][k][m]+t*t,dp[a-1][i][m+1][k][s]+t2*t2));
						}
						dp[a][i][j][k][s]=minmin;
					}
				}
			}
		}
	}
	return dp[k][0][0][7][7];
}
int main(){
	while (cin>>n){		
		for (int i=0;i<8;i++){
			int s=0;
			for (int j=0;j<8;j++){
				cin>>a[i][j];
				s+=a[i][j];
				if (i==0)	
					sum[i][j]=s;
				else
					sum[i][j]=sum[i-1][j]+s;
			}
		}
		double ans = n*fun(n-1)-sum[7][7]*sum[7][7];
		cout<<fixed<<setprecision(3)<<sqrt(ans/(n*n))<<endl;
	}
	return 0;
}