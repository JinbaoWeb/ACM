#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
	int t,n;
	int x;
	int a[105];
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		if (a[0]!=a[1])
			cout<<a[0]<<endl;
		if (a[n-1]!=a[n-2])
			cout<<a[n-1]<<endl;
	}
	
	return 0;
}
