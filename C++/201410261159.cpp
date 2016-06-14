#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int t;
	long long n;
	cin>>t;
	while (cin>>n){
		long long a=2,b=1;
		while (n){
			if (n%2){
				b=b*a;
				b=b%(1000000007);
			}
			a=a*a;
			n/=2;
			cout<<a<<endl;
		}
		cout<<b-1<<endl;
	}
	return 0;
} 
