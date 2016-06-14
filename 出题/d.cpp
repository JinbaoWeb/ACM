#include <iostream>
#include <fstream>
using namespace std;
int f(int x){
	if (x==1 || x==0)
		return 1;
	return f(x-1)+3*f(x-2);
}
int main(){
	ifstream cin("d.in");
	ofstream cout("d.out");
	int t,n,m;
	cin>>t;
	while (t--){
		cin>>n;
		cout<<f(n)<<endl;
	}
	return 0;
}