#include <iostream>
using namespace std;
int main(){
	int a,b,t;
	cin>>t;
	while (t--){
		cin>>a>>b;
		if (a<b)
			swap(a,b);
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}