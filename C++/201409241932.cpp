#include <iostream>
using namespace std;
int main(){
	long long t,n,m,k;
	cin>>t;
	while (cin>>m>>n>>k){
		if (m<=k)
			cout<<"infinite"<<endl;
		else{
			long long sum=n;
			long long left=0;
			while (n){
				long long s=(k*n+left)/m;
				left=k*n+left-s*m;
				n=s;
				sum+=n;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
