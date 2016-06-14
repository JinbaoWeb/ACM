#include <iostream>
using namespace std;
int Count(int x){
	for (int i=1;i<=16;i=i<<1){
		x=x^(x>>i);
	}
	return x&1;
}
int main(){
	int x;
	while (cin>>x){
		cout<<Count(x)<<endl;
	}

	return 0;
}