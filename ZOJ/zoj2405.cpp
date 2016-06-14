#include <iostream>
using namespace std;
int solve(int n,int d){
	int sum=0;
	while (n){
		sum+=n%d;
		n/=d;
	}
	return sum;
}
int main(){
	for (int i=1000;i<10000;i++){
		if (solve(i,12)==solve(i,10) && solve (i,10)==solve(i,16)){
			cout<<i<<endl;
		}
	}
	return 0;
}
