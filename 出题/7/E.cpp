#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
int b[1000];
bool check(int n,int a[]){
	bool flag=true;
	for (int i=1;i<n;i++){
		if (a[i]<a[i-1]){
			flag=false;
			break;
		}
	}
	return flag;
}
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		int l=0,r=0;
		while (check(n,a)==false){
			l++;
			if (l%2==1)
				sort(a,a+n-1);
			else
				sort(a+1,a+n);
		}
		while (check(n,b)==false){
			r++;
			if (r%2==0)
				sort(b,b+n-1);
			else
				sort(b+1,b+n);
		}
		int ans=min(l,r);
		cout<<ans<<endl;
	}
	return 0;
}