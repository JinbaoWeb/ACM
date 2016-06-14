#include <iostream>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		int i=0,flag=0;
		while (n){
			if (n%2==1){
				if (flag==0)
					cout<<i;
				else
					cout<<" "<<i;
				flag=1;
			}
			i++;
			n/=2;
		}
		cout<<endl;
	}
	return 0;
}