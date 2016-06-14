#include <iostream>
using namespace std;
int main(){
	long long sum=0,a,n,k,t;
	cin>>t;
	while (cin>>a>>n){
		sum=0;
		k=a;
		for (int i=1;i<=n;i++){
			sum+=k;
			k=k*10+a;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
