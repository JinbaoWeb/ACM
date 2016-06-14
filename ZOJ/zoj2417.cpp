#include <iostream>
using namespace std;
int main(){
	int n;
	while (cin>>n&&n){
		int k=0;
		while (n){
			if (n%2==1)
				break;
			k++;
			n/=2;
		}
		int ans=1;
		for (int i=0;i<k;i++){
			ans*=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
