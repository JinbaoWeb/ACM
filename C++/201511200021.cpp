#include <iostream>
using namespace std;
int main(){
	int a,b;
	while (cin>>a>>b){
		int temp=(a+b|a!=b);
		cout<<temp<<endl;
	}

	return 0;
}