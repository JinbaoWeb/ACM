#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	int n,m;
	while (t--){
		cin>>n>>m;
		if (n<=m){
			cout<<"first"<<endl;
			continue;
		}
		if (n%(m+1)==0)
			cout<<"second\n";
		else
			cout<<"first\n";
	}

	return 0;
}