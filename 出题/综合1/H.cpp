#include <iostream>
using namespace std;
int main(){
	int t,n;
    cin>>t;
	while (t--){
        cin>>n;
		for (int i=1;i<=2*n-1;i++){
			if (i<n){
				for (int j=1;j<=n-i;j++)	//打印空格
					cout<<" ";
				for (int k=1;k<i;k++)
					cout<<n-k;
				for (int k=i;k<=2*i-1;k++)
					cout<<n-i+k-i;
				//for (int k=1;k<=2*i-1;k++)	//打印*
				//	cout<<"*";
			}
			else if (i==n){
				for (int i=n-1;i>=0;i--)
					cout<<i;
				for (int i=1;i<n;i++)
					cout<<i;
			}
			else{
				for (int j=1;j<=i-n;j++)	//打印空格
					cout<<" ";
				int temp=n-1;
				for (int k=1;k<(4*n-2*i)/2;k++)
					cout<<temp--;
				for (int k=(4*n-2*i)/2;k<(4*n-2*i);k++)
					cout<<temp++;
				//for (int k=1;k<(4*n-2*i);k++)	//打印*
				//	cout<<"*";
			}
			cout<<endl;
		}
	}
	return 0;
}