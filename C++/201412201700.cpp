#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
bool is(int *a,int n){
	for (int i=0;i<n;i++){
		if (a[i]!=a[n-1-i])
			return false;
	}
	return true;
}
int main(){
	int t,n,a[1001];
	cin>>t;
	while (t--){
		cin>>n;
		long long x=0,y=0;
		for (int i=0;i<n;i++){
			cin>>a[i];
			if (i%2==0)
				x+=a[i];
			else
				y+=a[i];
		}
		if (x==y&&is(a,n)==false)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}