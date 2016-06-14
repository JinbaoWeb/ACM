#include <iostream>
using namespace std;
int f(int n,int m){
	if (n<1 || m<1)
		return 0;
	if (n==1 || m==1)
		return 1;
	if (n<m)
		return f(n,n);
	if (n==m)
		return f(n,m-1)+1;
	return f(n,m-1)+f(n-m,m);
}
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		cout<<f(n,n)<<endl;
	}
	
	return 0;
} 
