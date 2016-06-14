#include <iostream>
using namespace std;
#define N 1000
int main(){
	int t,n;
	int a[N];
	cin>>t;
	while (t--){
		cin>>n;
		int sum=0;
		for (int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}