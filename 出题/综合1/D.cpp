#include <iostream>
using namespace std;
int f(int n){
	if (n==0)
		return 0;
	if (n==1 || n==2)
		return 1;
	return f(n-1)+f(n-2)+f(n-3);
}
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		cout<<f(n)<<endl;
	}
	return 0;
}