#include <bits/stdc++.h>
using namespace std;
#define N 100000
typedef long long ll;
int main(){
	int n,a[N],x;
	cin>>n;
	int cnt=0;
	ll sum=0;
	for (int i=0;i<n;i++){
		cin>>x;
		sum+=x;
		if (x%2==1){
			a[cnt++]=x;
		}
	}
	sort(a,a+cnt);
	if (cnt%2==1){
		sum-=a[0];
	}
	cout<<sum<<endl;
	return 0;
} 
