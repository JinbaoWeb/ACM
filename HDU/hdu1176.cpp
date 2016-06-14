#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int map[100000+5][11];
int Max(int a,int b,int c){
	if (a>b)
		return a>c?a:c;
	return b>c?b:c;
}
int main(){
	int n,x,y;
	while (scanf("%d",&n)!=EOF){
		if (n==0)
			break;
		memset(map,0,sizeof(map));
		while (n--){
			scanf("%d%d",&y,&x);
			map[x][y]++;
		}
		/*
		for (int i=0;i<5;i++){
			for (int j=0;j<11;j++)
				cout<<map[i][j]<<"  ";
			cout<<endl;
		}
		cout<<endl;
		*/
		for (int i=100000-1;i>=0;i--){
			for (int j=0;j<11;j++){
				int temp=0;
				if (j>0 && j<10)
					map[i][j]+=Max(map[i+1][j-1],map[i+1][j],map[i+1][j+1]);
				if (j==0)
					map[i][j]+=Max(0,map[i+1][j],map[i+1][j+1]);
				if (j==10)
					map[i][j]+=Max(map[i+1][j-1],map[i+1][j],0);
			}
		}
		/*
		for (int i=0;i<5;i++){
			for (int j=0;j<11;j++)
				cout<<map[i][j]<<"  ";
			cout<<endl;
		}
		*/
		cout<<map[0][5]<<endl;
	}

	return 0;
}