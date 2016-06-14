#include <iostream>
using namespace std;
int main(){
	int a,n;
	while (cin>>a>>n){
		a>>=1;	//什么

		cout<<a<<endl;
		cout<<"n= "<<(n&1)<<endl;
	}
	return 0;
}