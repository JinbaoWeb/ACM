#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
char map[20][20];
bool used[20][20];
int t,n,m;
int dix[] = {-1, 0, 1, 0};
int diy[] = { 0, 1, 0,-1};
bool check(int mm,int nn){
	for (int k=0;k<4;k++){
		int x=mm+dix[k],y=nn+diy[k];
		if (x<0 || x>=n || y<0 || y>=m)
			continue;

		swap(map[x][y],map[mm][nn]);
		/*cout<<"------------"<<endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++)
				cout<<map[i][j]<<" ";
			cout<<endl;
		}
		*/
		if (y-2>=0){
			if (map[x][y-2]==map[x][y-1] && map[x][y-1]==map[x][y]){
				//cout<<x<<" "<<y<<" "<<map[x][y]<<endl;
				//cout<<"1"<<endl;
				swap(map[x][y],map[mm][nn]);
				return true;
			}
		}

		if (y-1>=0 && y+1<m){
			if (map[x][y-1]==map[x][y] && map[x][y+1]==map[x][y]){
				//cout<<x<<" "<<y<<" "<<map[x][y]<<endl;
				//cout<<"2"<<endl;
				swap(map[x][y],map[mm][nn]);
				return true;
			}
		}
		if (y+2<m){
			if (map[x][y]==map[x][y+1] && map[x][y+1]==map[x][y+2]){
				//cout<<x<<" "<<y<<" "<<map[x][y]<<endl;
				//cout<<"3"<<endl;
				swap(map[x][y],map[mm][nn]);
				return true;
			}
		}

		if (x-2>=0){
			if (map[x-2][y]==map[x-1][y] && map[x-1][y]==map[x][y]){
				//cout<<x<<" "<<y<<" "<<map[x][y]<<endl;
				//cout<<"4"<<endl;
				swap(map[x][y],map[mm][nn]);
				return true;
			}
		}


		if (x-1>=0 && x+1<n){
			if (map[x-1][y]==map[x][y] && map[x][y]==map[x+1][y]){
				//cout<<x<<" "<<y<<" "<<map[x][y]<<endl;
				//cout<<"5"<<endl;
				swap(map[x][y],map[mm][nn]);
				return true;
			}
		}
		if (x+2<n){
			if (map[x][y]==map[x+1][y] && map[x+1][y]==map[x+2][y]){
				//cout<<x<<" "<<y<<" "<<map[x][y]<<endl;
				//cout<<"6"<<endl;
				swap(map[x][y],map[mm][nn]);
				return true;
			}
		}

		swap(map[x][y],map[mm][nn]);
		/*
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++)
				cout<<map[i][j]<<" ";
			cout<<endl;
		}
		cout<<"------------"<<endl;
		*/
		
	}
	return false;
}
int main(){
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n>>m;
		for (int i=0;i<n;i++)
			cin>>map[i];
		int count=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (check(i,j)==true){
					//cout<<i<<" "<<j<<endl;
					count++;
				}
			}
		}
		cout<<"Case #"<<cas<<": "<<count<<endl;
	}
	return 0;
}