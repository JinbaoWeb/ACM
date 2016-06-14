#include <iostream>
using namespace std;
typedef long long ll;
const int INF = 0xffffffff;
ll Fib[50];
int main(){
	int i;
	ll m,n;
	Fib[0]=Fib[1]=1;
	for (i=2;i<44;i++){
		Fib[i]=Fib[i-1]+Fib[i-2];
	}
	while (cin>>m>>n){
		int k=43,flag=0;
		while (k--){
			if (m%Fib[k]==0 || n%Fib[k]==0){
				flag=1;
				break;
			}
		}
		if (flag==0)
			cout<<0<<endl;
		else
			cout<<n*m-n*m/Fib[k]<<endl<<endl;
	}
	return 0;
}