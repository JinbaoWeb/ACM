/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-01 19:06
 * Filename :        201505011900.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
using namespace std;
int main(){
	int t,n,m,q;
	int a[105][105];
	cin>>t;
	while (t--){
		cin>>n>>m>>q;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++)
				cin>>a[i][j];
		}
		if (q==1){
			for (int i=0;i<m;i++){
				for (int j=n-1;j>0;j--)
					cout<<a[j][i]<<" ";
				cout<<a[0][i]<<endl;
			}
		}
		else{
			for (int i=m-1;i>=0;i--){
				for (int j=0;j<n-1;j++)
					cout<<a[j][i]<<" ";
				cout<<a[n-1][i]<<endl;
			}
		}
	}
	
	return 0;
}
