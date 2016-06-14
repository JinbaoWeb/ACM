#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream cin("Frint.in");
	ofstream cout("Frint.out");
	int n;
	while (cin>>n){
		for (int i=1;i<=2*n-1;i++){
			if (i<n){
				for (int j=1;j<=n-i;j++)	//打印空格
					cout<<" ";
				for (int k=1;k<=2*i-1;k++)	//打印*
					cout<<"*";
			}
			else if (i==n){
				for (int j=1;j<=2*n-1;j++)
					cout<<"*";
			}
			else{
				for (int j=1;j<=i-n;j++)	//打印空格
					cout<<" ";
				for (int k=1;k<(4*n-2*i);k++)	//打印*
					cout<<"*";
			}
			cout<<endl;
		}
	}
	return 0;
}