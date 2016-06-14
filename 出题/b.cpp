#include <iostream>
#include <fstream>
using namespace std;
int main(){
	int t,a,b;
	//ifstream cin("b.in");
	//ofstream cout("b.out");
	cin>>t;
	while (t--){
		cin>>a>>b;
		int ans=0;
		for (int j=a;j<=b;j++){
			int i=j;
			int temp=0;
			while (i){
				temp+=i%10;
				i/=10;
			}
			ans+=temp;
		}
		cout<<ans<<endl;
	}
	return 0;
}