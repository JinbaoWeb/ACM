#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int a[100];
	while (cin>>n){
		for (int i=1;i<=n;i++)
			cin>>a[i];
		int x;
		cin>>x;
		cout<<lower_bound(a+1,a+n+1,x)-a<<endl;
		cout<<upper_bound(a+1,a+n+1,x)-a<<endl;
		cout<<binary_search(a+1,a+n+1,x)<<endl;
	}
	return 0;
}