#include <iostream>
#include <fstream>
using namespace std;
bool fib[1000000000];
int main(){
	ofstream cout("22.txt");
	int k=2,a=0,b=1,c=0;
	cout<<0<<","<<1<<",";
	while (c<1000000000){
		c=a+b;
		cout<<c<<",";
		a=b;
		b=c;
		k++;
	}
	return 0;
}