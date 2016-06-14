#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream cin("Factorial.in");
	ofstream cout("Factorial.out");
	int n;
	while (cin>>n){
		int ans=0;
		int mul=1;
		for (int i=1;i<=n;i++){
			mul*=i;
			ans+=mul;
		}
		cout<<ans<<endl;
	}
	return 0;
}