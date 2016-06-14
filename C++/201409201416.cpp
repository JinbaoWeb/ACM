#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
char map[105][105];
bool vis[105][105];
int ax[9]={0,-1,1,0,0,-1,-1,1,1};
int bx[9]={0,0,0,-1,1,-1,1,-1,1};
int step=1;
int maxstep=2;
void dfs(int row,int column,int dir,int turn)
{
	int k;
	int xx,yy;
	for(k=1;k<9;k++){
		xx=row+ax[k];
		yy=column+bx[k];
		if(xx<0||xx>=n||yy<0||yy>=n||vis[xx][yy]||map[xx][yy]=='#')
			continue;
		if(dir==0)
			dir=k;
		if(turn){
			if(dir!=k)
				continue;
		}
		else{
			if(dir<=4&&k>4)
				continue;
			if(dir>4&&k<=4)
				continue;
		}
		if(turn==0){
			vis[xx][yy]=1;
		}
		if(dir!=k){
			turn=1;
			dir=k;
		}
		step++;
		if(step>maxstep)
			maxstep=step;
		dfs(xx,yy,dir,turn);
		vis[xx][yy] = 0;
	}
	if(step>maxstep)
		maxstep=step;
	step--;
}
int main()
{
	int i,j;
	while(cin>>n&&n){
		int flag=0;
		for(i=0;i<n;i++){
			cin>>map[i];
		}
		maxstep=2;
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(map[i][j]=='.'&&vis[i][j]==0){
					step=1;
					vis[i][j]=1;
					dfs(i,j,0,0);
					if(step>maxstep)
						maxstep=step;
				}
			}
		}
		cout<<maxstep<<endl;
	}
	return 0;
}

