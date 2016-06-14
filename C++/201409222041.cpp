#include <iostream>
using namespace std;
int gcd(int a,int b){
	if (!a||!b)
		return a>b?a:b;
	for (int t;t=a%b;a=b,b=t);
	return b;
}
int main(){
	int a,b,c,d,n;
	char x,y,z;
	cin>>n;
	while (cin>>a>>x>>b>>y>>d>>z>>c){
		int k1=a*c,k2=b*d,k3=b*c;
		if (y=='+')
			k1+=k2;
		else
			k1-=k2;
		int k=gcd(k1,k3);
		k1/=k;
		k3/=k;
		cout<<k1<<x<<k3<<endl;
	}
	return 0;
}
