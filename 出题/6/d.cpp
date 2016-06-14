#include <iostream>
using namespace std;
int a[101][101];
int main(){
	int x,y,t,n,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		int Max=-1;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cin>>a[i][j];
				if (a[i][j]>Max){
					Max=a[i][j];
					x=i,y=j;
				}
			}
		}
		cout<<Max<<endl;
	}
	return 0;
}