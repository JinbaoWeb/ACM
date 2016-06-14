#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 100+5;
#define max(a,b) a>b?a:b
int dp[MAXN][MAXN][MAXN][6];
int main(){
	int n,v1,v2,k;
	int a,b,val;
	while (~scanf("%d%d%d%d",&n,&v1,&v2,&k)){
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&val);
			for (int j=0;j<=v1;j++){
				for (int x=0;x<=v2;x++){
					for (int y=0;y<=k;y++){
						dp[i][j][x][y]=dp[i-1][j][x][y];
						if (y>=1)
							dp[i][j][x][y]=max(dp[i][j][x][y],dp[i-1][j][x][y-1]+val);
						if (x>=b)
							dp[i][j][x][y]=max(dp[i][j][x][y],dp[i-1][j][x-b][y]+val);
						if (j>=a)
							dp[i][j][x][y]=max(dp[i][j][x][y],dp[i-1][j-a][x][y]+val);
					}
				}
			}
		}	
		cout<<dp[n][v1][v2][k]<<endl;
	}

	return 0;
}