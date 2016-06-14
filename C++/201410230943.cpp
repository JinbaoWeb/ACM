#include <iostream>
using namespace std;
#define MAX 30+1
int main(){
	int n,map[MAX][MAX];
	while (cin>>n){
		int num=1;
		for (int i=0;i<n;i++){
			for (int j=i;j<n;j++)
				map[i][j]=num++;
			for (int k=i+1;k<n;k++)
				map[k][i]=num++;
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n-1;j++)
				cout<<map[i][j]<<" ";
			cout<<map[i][n-1]<<endl;
		}
			
	}
	return 0;
}
