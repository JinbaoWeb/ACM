#include <iostream>
using namespace std;
#define N 5
int f(int a[]){
	int sum=0;
	for (int i=0;i<5;i++)
		sum+=a[i];
	return sum/5+(sum%5>2?1:0);
}
int main(){
	int t;
	int a[N];
	cin>>t;
	while (t--){
		for (int i=0;i<5;i++){
			cin>>a[i];
		}
		int ans=f(a);
		cout<<ans<<endl;
	}
	return 0;
}