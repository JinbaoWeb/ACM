/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-01 01:22
 * Filename :        201505010122.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char map[505][505];
int dir_x[]={ 0, 1,0,-1};
int dir_y[]={-1, 0,1, 0};
int n,m;
int a,b,c,d;
int flag=0;
bool dfs(int x,int y){
	map[x][y]='X';
	if (x==c && y==d)
		return true;
	for (int i=0;i<4;i++){
		if (x+dir_x[i]==c && y+dir_y[i]==d && map[x+dir_x[i]][y+dir_y[i]]=='X'){
			flag=1;
			return true;
		}
		if (((x+dir_x[i])<=n&&(x+dir_x[i])>=1) && ((y+dir_y[i])<=m&&(y+dir_y[i])>=1) && map[x+dir_x[i]][y+dir_y[i]]=='.'){
			if (dfs(x+dir_x[i],y+dir_y[i])==true)
				return true;
			else
				map[x+dir_x[i]][y+dir_y[i]]='.';
		}
	}
	return false;
}
int main(){
	while (~scanf("%d%d",&n,&m)){
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf("\n%c",&map[i][j]);
		scanf("%d%d%d%d",&a,&b,&c,&d);
		flag=0;
		if (dfs(a,b)==true){
			for (int i=0;i<4;i++){
				if (map[c+dir_x[i]][d+dir_y[i]]=='.'){
					flag=1;
					break;
				}
			}
			if (flag==0)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else
			printf("NO\n");
	}

	return 0;
}