#include <iostream>
using namespace std;
int a[1000+5];
int main(){
	int n;
	while (cin>>n){
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		int flag=0;
		int ans=(n-a[0])%n;
		//cout<<ans<<endl;
		for (int i=1;i<n;i++){
			int k;
			if (i%2==0){
				if (a[i]<i)
					k=i-a[i];
				else
					k=n+i-a[i];
			}
			else{
				if (a[i]>i)
					k=a[i]-i;
				else
					k=n-i+a[i];
			}
			k%=n;
			if (k!=ans){
				flag=1;
				break;
			}
		}
		if (flag==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No\n";
	}
	return 0;
}