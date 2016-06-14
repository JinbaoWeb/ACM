#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[100];
int main(){
	int n,a,temp;
	cin>>n>>a;
	ll x=0;
	for (int i=0;i<n;i++){
		cin>>temp;
		x=x*a+temp;
	}
	cin>>n>>a;
	ll y=0;
	for (int i=0;i<n;i++){
		cin>>temp;
		y=y*a+temp;
	}
	cout<<x<<" "<<y<<endl;
	if (x<y)
		cout<<"<"<<endl;
	else if (x==y)
		cout<<"="<<endl;
	else
		cout<<">"<<endl;
	return 0;
}