#include <iostream>
using namespace std;
int gcd(int x, int y){
	if (!x || !y) return x > y ? x : y;
	for (int t; t = x % y; x = y, y = t);
	return y;
}
int main(){
	int a,b,k;
	while (cin>>a>>b>>k){
		int count=0;
		for (int i=1;i<=a;i++){
			for (int j=1;j<=b;j++){
				if (gcd(i,j)==k){
					cout<<i<<"    "<<j<<endl;
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}