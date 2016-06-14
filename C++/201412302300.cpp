#include <iostream>
using namespace std;
int main(){
	int n,m,a[30002];
	while (cin>>n>>m){
		for (int i=0;i<n-1;i++){
			cin>>a[i];
		}
		int k=1,flag=0;
		while (1){
			
			if (k>m)
				break;
			if (k==m){
				flag=1;
				break;
			}
			k=k+a[k-1];
		}
		if (flag==0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}