#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int a[105],t,n,index;
	cin>>t;
	while (t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++){
			cin>>index;
			a[index]++;
		}
		int max=0,max_i=0;
		for (int i=0;i<=n;i++){
			if (a[i]>max){
				max=a[i];
				max_i=i;
			}
		}
		cout<<max_i<<endl;
	}
	return 0;
}