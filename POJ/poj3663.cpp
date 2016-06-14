#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 20000+2
int main(){
	int a[MAX],n,s;
	while (cin>>n>>s){
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int ans=0,k;
		for (k=n-1;k>0;k--){
			if (a[k]+a[k-1]<=s)
				break;
		}
		ans+=k*(k-1)/2;
		for (;k<n;k++){
			for (int i=0;i<k;i++){
				if (a[k]+a[i]<=s)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}