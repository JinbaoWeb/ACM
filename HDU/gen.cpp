#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int T = 20;
	cout<<T<<endl;
	while(T--) {
		int n = 1000;
		cout<<n<<endl;
		for(int i = 1; i <= n; ++i) {
			cout<<i<<' ';
		}
		cout<<endl;
	}
}