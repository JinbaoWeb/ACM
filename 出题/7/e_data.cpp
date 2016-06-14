#include <bits/stdc++.h>
#include <cstdlib> 
#include <algorithm>
using namespace std;
int a[1000];
int main(){
	int n,t;
	t=rand()%100+1;
	cout<<t<<endl;
	while (t--){
		n=rand()%999+1;
		cout<<n<<endl;
		for (int i=0;i<n;i++)
			a[i]=i+1;
		int k=rand();
		while (k--){
			next_permutation(a,a+n);
		}
		for (int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}