#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000];
int main(){
	int n;
	while (cin>>n){
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for (int i=0;i*2<n;i++){
			if (n%2==1 && i==n/2)
				cout<<a[i]<<endl;
			else if (n%2==0 && i==n/2)
				cout<<a[i]<<" "<<a[n-1-i]<<endl;
			else
				cout<<a[i]<<" "<<a[n-1-i]<<" ";
		}

	}

	return 0;
}