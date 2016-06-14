#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int a[1000000+10];
int b[1000+10];
int main(){
	int t,n,k,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=0;i<n;i++)
			cin>>b[i];
		int k=0;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				a[k++]=abs(b[i]-b[j]);
			}
		}
		sort(a,a+k);
		for (int i=0;i<k;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		cout<<a[m-1]<<endl;
	}

	return 0;
}