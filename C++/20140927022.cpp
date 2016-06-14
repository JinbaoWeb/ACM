#include <iostream>
using namespace std;
int main(){
	long long n;
	while (cin>>n){
		int count=0;
		long long k=1;
		while (n>=((3*k*k+k)/2)){
			if (k%3==1&&n%3==2)
				count++;
			if (k%3==2&&n%3==1)
				count++;
			if (k%3==0&&n%3==0)
				count++;
			k++;
		}
		cout<<count<<endl;
	}
	return 0;
}
