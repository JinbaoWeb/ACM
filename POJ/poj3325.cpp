#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,a[105];
	while (cin>>n){
		if (n==0)
			break;
		int sum=0;
		for (int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}		
		sort(a,a+n);
		sum=sum-a[0]-a[n-1];
		cout<<sum/(n-2)<<endl;
	}
	return 0;
}
