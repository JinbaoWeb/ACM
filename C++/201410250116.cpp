#include <iostream>
using namespace std;
long long gcd(long long x, long long y){
	if (!x || !y) return x > y ? x : y;
	for (long long t; t = x % y; x = y, y = t);
	return y;
}
int main(){
	long long l,r,a,b,c;
	while (cin>>l>>r){
		int flag=0;
		for (a=l;a<r;a++){
			for (b=a+1;b<r;b++){
				for (c=b+1;c<=r;c++){
					if (gcd(a,b)==1 && gcd(b,c)==1 && gcd(a,c)!=1){
						cout<<a<<" "<<b<<" "<<c<<endl;
						flag=1;
						break;
					}
				}
			}
		}
		if (!flag)
			cout<<-1<<endl;
	}
	return 0;
} 
