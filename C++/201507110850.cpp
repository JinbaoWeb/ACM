#include <iostream>
using namespace std;
int f(int k){
	int ans=0;
	while (k){
		if (k%2==1)
			ans++;
		k/=2;
	}
	if (ans%2==0)
		return 1;
	return 0;
}
int main(){
	int a[10][10];
	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			int k=(i|j)^i;
			a[i][j]=f(k);
		}
	}
	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}