#include <iostream>
using namespace std;
int main(){
	int n,i;
	int a[]={1,2,4,7,15};
	while (cin>>n){
		if (n-15>0)
			i=5;
		else if (n-7>0)
			i=4;
		else if (n-4>0)
			i=3;
		else if (n-2>0)
			i=2;
		else if (n-1>0)
			i=1;
		while (i-->1){
			cout<<n-a[i]<<" ";
		}
		cout<<n-1<<endl;
	}
	return 0;
}