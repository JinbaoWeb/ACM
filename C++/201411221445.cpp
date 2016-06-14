#include <iostream>
using namespace std;
int main(){
	int n,map[55][55],ans[55][55];
	while (cin>>n){
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				cin>>map[i][j];
		int flag=n%2;
		

		//first
		for (int i=0;i<n;i+=2)
			for (int j=0;j<n;j++)
				ans[i][j]=map[i][j];
		for (int i=1;i<n;i+=2){
			for (int j=0;j<n;j++)
				ans[n-i-flag][j]=map[i][j];
		}
		
		//second
		for (int j=0;j<n;j+=2)
			for (int i=0;i<n;i++)
				map[i][j]=ans[i][j];
		for (int j=1;j<n;j+=2)
			for (int i=0;i<n;i++)
				map[i][n-j-flag]=ans[i][j];
		
		//third
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				ans[j][n-i-1]=map[i][j];
		//test
		
		if (flag==1){
			for (int i=0;i<n;i++){
				for (int j=0;j<n-1;j++)
					cout<<ans[i][n-1-j]<<" ";
				cout<<ans[i][0]<<endl;
			}
		}
		else{
			for (int i=0;i<n;i++){
				for (int j=0;j<n-1;j++)
					cout<<ans[i][j]<<" ";
				cout<<ans[i][n-1]<<endl;
			}
		}
			
		

	}
	return 0;
}