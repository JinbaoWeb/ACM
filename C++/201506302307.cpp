#include <iostream>
using namespace std;
int main(){
	int n;
	int a1,b1,a2,b2,a3,b3;
	cin>>n;
	cin>>a1>>b1>>a2>>b2>>a3>>b3;
	for (int i=a3;i<=b3;i++){
		if (a2+a1>n-i || b2+b1<n-i)
			continue;
		int flag=0;
		for (int j=a2;j<=b2;j++){
			if (i+j>n)
				break;
			int k=n-i-j;
			if (a1<=k && k<=b1){
				cout<<k<<" "<<j<<" "<<i<<endl;flag=1;
				break;
			}
		}
		if (flag==1)
			break;
	}
	
	return 0;
}