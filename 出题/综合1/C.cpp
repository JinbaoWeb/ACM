#include <iostream>
using namespace std;
bool isprime(int x){
	if (x<2)
		return false;
	for (int i=2;i*i<=x;i++){
		if (x%i==0)
			return false;
	}
	return true;
}
int main(){
	int t,x;
	cin>>t;
	while (t--){
		cin>>x;
		if (isprime(x)==false)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}