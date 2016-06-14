#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[100000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ll n,m;
	while (cin>>n>>m){
		m=n*n-m;
		int k=1;
		while (k*k<=m)
			k++;
		cout<<k<<" - "<<endl;
		int s=0;
		a[s++]=k*k*3;
		for (int i=k+1;i<=n;i++){
			a[s++]=k*k+100000*k+i*i-100000*i+i*k;
			a[s++]=k*k-100000*k+i*i+100000*i+i*k;
		}
		sort(a,a+s,cmp);
		for (int i=0;i<s;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		cout<<m-k*k<<" "<<a[m-k*k]<<endl;
	}

	return 0;
}