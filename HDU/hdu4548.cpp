#include <iostream>
using namespace std;
int count[1000000+5];
bool isprime(int n){
	if (n<2)
		return false;
	if (n==2 || n==3 || n==5 || n==7)
		return true;
	for (int i=2;i*i<=n;i++){
		if (n%i==0)
			return false;
	}
	return true;
}
bool f(int n){
	if (isprime(n)==true){
		int sum=0;
		while (n){
			sum+=n%10;
			n/=10;
		}
		if (isprime(sum)==true)
			return true;
		return false;
	}
	return false;
}
int main(){
	count[0]=count[1]=0;
	for (int i=2;i<=1000003;i++){
		count[i]=count[i-1];
		if (f(i)==true)
			count[i]++;
	}
	int t,x,y;
	while (cin>>t){
		for (int i=1;i<=t;i++){
			cin>>x>>y;
			cout<<"Case #"<<i<<": ";
			int ans=count[y]-count[x];
			if (f(x)==true)
				cout<<ans+1<<endl;
			else
				cout<<ans<<endl;
		}
	}
	return 0;
}