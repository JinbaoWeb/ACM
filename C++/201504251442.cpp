#include <iostream>
using namespace std;
bool isprime(int n){
	if (n==2 || n==3||n==5||n==7)
		return true;
	for (int i=2;i*i<=n;i++)
		if (n%i==0)
			return false;
	return true;
}
int main(){
	int k=0;
	for (int i=3;i<500000;i++){
		if (isprime(i)==true){
			k++;
			cout<<i<<",";
		}
	}
	cout<<endl<<k<<endl;

	return 0;
}
