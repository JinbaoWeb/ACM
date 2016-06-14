#include <iostream>
#include <fstream>
using namespace std;
int main(){
	//ifstream cin("a.in");
	//ofstream cout("a.out");
	int t,a,b,c;
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>a>>b>>c;
		if (b*b<4*a*c){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}

	return 0;
}