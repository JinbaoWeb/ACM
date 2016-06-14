#include <iostream>
using namespace std;
int main(){
	int t,n,k;
	cin>>t;
	while (t--){
		cin>>n>>k;
		if (n<k)
			cout<<0<<endl;
		else{
			int r=n%k;
			if (r<=k/2){
				cout<<n*n-r*r<<endl;
			}
			else{
				cout<<n*n-(k-r)*(k-r)<<endl;
			}
		}
	}
	return 0;
}