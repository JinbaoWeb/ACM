#include <iostream>
using namespace std;
int main(){
	int t,n,a[857002];
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		long long sum=0,temp=0;
		for (int i=0;i<n;i++){
			temp=0;
			for (int j=i;j<n;j++){
				temp+=a[j];
				sum+=temp;
				temp%=1000000007;
				sum%=1000000007;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
