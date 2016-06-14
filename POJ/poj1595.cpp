#include <iostream>
using namespace std;
bool isprime(int n){
	if (n==2||n==3||n==5||n==7||n==11)
		return true;
	for (int i=2;i*i<n;i++){
		if (n%i==0)
			return false;
	}
		
	return true;
}
int main(){
	int n,c;
	int prime[1000],k=0;
	for (int i=2;i<1005;i++)
		if (isprime(i)==true)
			prime[k++]=i;
	while (cin>>n>>c){
		cout<<n<<" "<<c<<":";
		int p=0;
		while (prime[p++]<=n);
		if (p%2){
			if (c*2>=p){
				for (int i=0;i<p;i++)
					cout<<" "<<prime[i];
				cout<<endl<<endl;
			}
			else{
				int q=(p-c*2)/2;
				for (int i=q;;i++){
					if (i-q>=c*2)
						break;
					cout<<" "<<prime[i];
				}
				cout<<endl<<endl;
			}
		}
		else{
			if (c*2-1>=p){
				for (int i=0;i<p;i++)
					cout<<" "<<prime[i];
				cout<<endl<<endl;
			}
			else{
				int q=(p-c*2)/2;
				for (int i=q;;i++){
					if (i-q>c*2-1)
						break;
					cout<<" "<<prime[i];
				}
				cout<<endl<<endl;
			}
		}
	}
	return 0;
}
