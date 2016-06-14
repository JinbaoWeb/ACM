#include <iostream>
using namespace std;
int gcd(int x, int y){
if (!x || !y) return x > y ? x : y;
for (int t; t = x % y; x = y, y = t);
return y;
}
int main(){
	int a,b,c,d;
	int t;
	cin>>t;
	while (cin>>a>>b>>c>>d){
		int x=a*d+b*c,y=b*d;
		int k=gcd(x,y);
		cout<<x/k<<" "<<y/k<<endl;
	}

	return 0;
}