#include <iostream>
using namespace std;
int a[10000];
bool isprime(int n){
	if (n==2||n==3||n==5||n==7)
		return true;
	for (int i=2;i*i<=n;i++)
		if (n%i==0)
			return false;
	return true;
}
int main(){
	int k=0;
	for (int i=2;i<1000;i++){
		if (isprime(i)==true)
			a[k++]=i;
	}
	
	int n;
	while (cin>>n){
		int count=0;
		for (int i=0;i<k;i++){
			for (int j=i;j<k;j++){
				for (int p=j;p<k;p++){
					if (a[i]+a[j]+a[p]==n)
						count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}