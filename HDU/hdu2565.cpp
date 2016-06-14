#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (i==j || i==n-j-1){
					cout<<"X";
					if (i*2<n && i==n-j-1)
						break;
					if (i*2>n && i==j)
						break;
				}
				else
					cout<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}