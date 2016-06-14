#include <iostream>
using namespace std;
int main(){
	int n;
	while (cin>>n){
		int count=0;
		for (int i=1;i<=n;i++){
			int ans=n-i*(i-1)/2;
			if (ans<=0)
				continue;
			if (ans%i==0){
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}