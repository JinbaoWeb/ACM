#include <iostream>
using namespace std;
int main(){
	int t,n,k,a[100002];
	cin>>t;
	while (t--){
		cin>>n>>k;
		int max=-0xffffff;
		for (int i=0;i<n;i++){
			cin>>a[i];
			if (a[i]>max)
				max=a[i];
		}		
		while (k--){
			int maxmax=-0xffffff;
			for (int i=0;i<n;i++){
				a[i]=max-a[i];
				if (a[i]>maxmax)
					maxmax=a[i];
			}
			max=maxmax;
		}
		for (int i=0;i<n-1;i++)
			cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	}
	return 0;
}
