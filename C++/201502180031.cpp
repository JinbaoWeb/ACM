#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll a,b,s;
	while (cin>>a>>b>>s){
		if (a<0)	
			a=-a;
		if (b<0)
			b=-b;
		if (a+b==s)
			cout<<"Yes"<<endl;
		else{
			if (a+b<s){
				if ((a+b-s)%2==0)
					cout<<"Yes"<<endl;
				else
					cout<<"No"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
	}
	return 0;
}