#include <iostream>
using namespace std;
#define N 1000
int main(){
	int t,n;
	int a[N];
	cin>>t;
	while (t--){
		cin>>n;
		int Max=-1000,Min=1000;
		for (int i=0;i<n;i++){
			cin>>a[i];
			if (a[i]>Max)
				Max=a[i];
			if (a[i]<Min)
				Min=a[i];
		}
		cout<<Max-Min<<endl;
	}
	return 0;
}