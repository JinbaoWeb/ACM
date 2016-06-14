#include <iostream>
using namespace std;
#define M 50000
bool isprimer(int n){
	if (n<2)
		return false;
	if (n==2||n==3||n==5||n==7)
		return true;
	for (int i=2;i*i<=n;i++){
		if (n%i==0)
			return false;
	}
	return true;
}
int main(){
	bool a[M];
	for (int i=2;i<M;i++)
		a[i]=isprimer(i);
	int n;
	while (cin>>n&&n){
		int count=0;
		for (int i=2;2*i<=n;i++)
			if (a[i]==true&&a[n-i]==true)
				count++;
		cout<<count<<endl;
	}
	return 0;
}
