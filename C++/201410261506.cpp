#include <iostream>
using namespace std;
int main(){
	long long t,n,k,a[100002],b[100002];
	cin>>t;
	while (t--){
		cin>>n>>k;
		long long max=-2*1e9;
		for (int i=0;i<n;i++){
			cin>>a[i];
			if (a[i]>max)
				max=a[i];
		}
		long long maxmax=-2*1e9;
		for (int i=0;i<n;i++){
			a[i]=max-a[i];
		}
		for (int i=0;i<n;i++){
			if (a[i]>maxmax)
				maxmax=a[i];
		}
		for (int i=0;i<n;i++){
			b[i]=maxmax-a[i];
		}
		
		if (k%2){
			for (int i=0;i<n-1;i++)
				cout<<a[i]<<" ";
			cout<<a[n-1]<<endl;
		}
		else{
			for (int i=0;i<n-1;i++)
				cout<<b[i]<<" ";
			cout<<b[n-1]<<endl;
		}
	}
	return 0;
}
