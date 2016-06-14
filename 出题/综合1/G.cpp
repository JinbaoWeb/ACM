#include <iostream>
using namespace std;
int gcd(int a,int b){
	if (b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	int t,a,b,c;
	cin>>t;
	while (t--){
		cin>>a>>b>>c;
		int k1=gcd(a,b);
		int p1=a*b/k1;
		int k2=gcd(b,c);
		int p2=b*c/k2;
		int k=gcd(k1,k2);
		int k3=gcd(p1,p2);
		int p=p1*p2/k3;
		//cout<<k<<" "<<p<<endl;
		cout<<k+p<<endl;
	}
	return 0;
}