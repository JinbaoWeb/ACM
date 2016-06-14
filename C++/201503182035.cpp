#include <iostream>
using namespace std;
typedef long long ll;
ll f(ll a,ll b){
	if (a%b==0)
		return a/b;
	else
		return a/b+f(b,a-a/b*b);
}
int main(){
	ll a,b;
	while (cin>>a>>b){
		cout<<f(a,b)<<endl;
	}
	return 0;
}