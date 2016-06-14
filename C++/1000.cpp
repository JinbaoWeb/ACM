#include <iostream>
using namespace std;
int gcd(int a,int b){
	if (!a||!b)
		return a>b?a:b;
	for (int t;t=a%b;a=b,b=t);
	return b;
}
int main(){
	int t,a,b,k;
	cin>>t;
	while (t--){
		cin>>a>>b>>k;
		int s=gcd(a,b),num=0,flag=0;
		for (int i=1;i<=s;i++){
			if (s%i==0)
				num++;
			if (num==k){
				cout<<i<<endl;
				flag=1;
				break;
			}
		}
		if (flag==0)
			cout<<0<<endl;
	}
	return 0;
}
