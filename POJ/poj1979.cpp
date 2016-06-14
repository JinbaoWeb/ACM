#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
char map[22][22];
bool used[22][22];
int dp[22][22];
int n,m;
int dirx[]={ 0,-1,0,1};
int diry[]={-1, 0,1,0};
int dfs(int x,int y){
	int sum=0;
	if (used[x][y]==true)
		return 0;
	if (dp[x][y]!=0)
		return dp[x][y];
	used[x][y]=true;
	for (int i=0;i<4;i++){
		int xx=x+dirx[i],yy=y+diry[i];

		if (map[xx][yy]=='.' && used[xx][yy]==false && xx<m && xx>=0 && yy<n && yy>=0){
			sum+=dfs(xx,yy);
		}
	}
	dp[x][y]=sum+1;
	return sum+1;
}
int main(){
	
	while (cin>>n>>m){
		if (n==0&&m==0)
			break;
		int x,y;
		memset(used,false,sizeof(used));
		memset(dp,0,sizeof(dp));
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				cin>>map[i][j];
				if (map[i][j]=='@'){
					
					x=i;
					y=j;
				}
			}
		}
		cout<<dfs(x,y)<<endl;
	}
	return 0;
}