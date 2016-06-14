#include <iostream>
#include <algorithm>
using namespace std;
#define M 100
int main(){
	int a[M],i;
	a[0]=0;a[1]=1;a[2]=2;
	for (i=3;;i++){
		a[i]=a[i-2]+a[i-3];
		if (a[i]>1000000000)
			break;
	}
	sort(a,a+i);
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		int j;
		for (j=0;j<i-1;j++){
			if (a[j]<=n&&n<a[j+1])
				break;
		}
		if (n-a[j]>a[j+1]-n)
			cout<<a[j+1]<<endl;
		else
			cout<<a[j]<<endl;
	}
	return 0;
}
