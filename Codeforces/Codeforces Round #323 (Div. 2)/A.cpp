#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[100000],y[100000];
int main(){
	int a,b,n;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	cin>>n;
	for (int i=0;i<n*n;i++){
		cin>>a>>b;
		if (x[a]==0 && y[b]==0){
			cout<<i+1<<" ";
			x[a]=1,y[b]=1;
		}
	}
	return 0;
}