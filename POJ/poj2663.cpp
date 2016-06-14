#include <iostream>
using namespace std;
int main(){
	long long n,a[50];
	a[0]=1;a[2]=3; 
	for(int i=4;i<=30;i+=2)  
		a[i]=4*a[i-2]-a[i-4];  
	while (cin>>n&&n!=-1){
		if (n%2)
			cout<<0<<endl;
		else
			cout<<a[n]<<endl;
	}
	return 0;
}
