#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream cin("AplusB.in");
	ofstream cout("AplusB.out");
	int a,b;
	while (cin>>a>>b){
		cout<<a<<" + "<<b<<" = "<<a+b<<endl;
	}
	return 0;
}