#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,d,h;
	cin>>n>>d>>h;
	if (d>2*h){
		cout<<-1<<endl;
		return 0;
	}
	if (n>2 && d==1 && h==1){
		cout<<-1<<endl;
		return 0;
	}
	if (d==h){
		int i;
		for (i=1;i<=h;i++)
			cout<<i<<" "<<i+1<<endl;
		i++;
		for (;i<=n;i++)
			cout<<2<<" "<<i<<endl;
		return 0;
	}
	int i;
	for (i=1;i<=h;i++){
		cout<<i<<" "<<i+1<<endl;
	}
	i++;
	cout<<1<<" "<<i<<endl;
	for (int j=1;j<(d-h);j++){
		cout<<i<<" "<<i+1<<endl;
		i++;
	}
	i++;
	for (;i<=n;i++){
		cout<<1<<" "<<i<<endl;
	}
	return 0;
}