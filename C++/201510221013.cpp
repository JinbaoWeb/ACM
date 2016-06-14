#include <bits/stdc++.h>
using namespace std;
int main(){
	int x;
	while (cin>>x){
		while (x){
			cout<<x%2;
			x/=2;
		}
		cout<<endl;
	}
	return 0;
}