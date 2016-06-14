#include <iostream>
using namespace std;
int map[22][22];
int ans[22][22];
int check(int i,int j,int x,int y){
	if (map[i][j]<0)
		return map[x][y];
	if (map[i][j]>0)
		return -map[x][y];
}
int main(){
	int n,m;
	while (cin>>n>>m){
		if (n==0&&m==0)
			break;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++)
				cin>>map[i][j];
		}
		int max=-0xffffff,x,y;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				ans[i][j]=0;
				if (i+1<n)
					ans[i][j]+=check(i,j,i+1,j);
				if (j+1<m)
					ans[i][j]+=check(i,j,i,j+1);
				if (i-1>=0)
					ans[i][j]+=check(i,j,i-1,j);
				if (j-1>=0)
					ans[i][j]+=check(i,j,i,j-1);
				if (max<ans[i][j]){
					max=ans[i][j];
					x=i,y=j;
				}
			}
		}
		/*
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}*/
		cout<<x+1<<" "<<y+1<<" "<<max<<endl;
	}
	return 0;
}