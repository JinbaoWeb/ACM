#include <iostream>
using namespace std;
int main(){
	int t,n,k,a;
	cin>>t;
	while (t--){
		cin>>n>>k;
		int count=0;
		for (int i=0;i<n;i++){
			cin>>a;
			if (a%2==0)
				count++;
		}
		if (count>=k)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
