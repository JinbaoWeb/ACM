#include <iostream>
#include <string.h>
using namespace std;
bool isprime(int n){
	if (n<2)
		return false;
	if (n==2 || n==3 || n==5 || n==7)
		return true;
	for (int i=2;i*i<=n;i++)
		if (n%i==0)
			return false;
	return true;
}
int main(){
	int a,b,n;
	while (cin>>a>>b>>n){
		if (a==0&&b==0&&n==0)
			break;
		int num=1,sum;
		for (int i=0;num<=n;i++){
			sum=a+b*i;
			if (isprime(sum)==true)
				num++;
		}
		cout<<sum<<endl;
	}
	return 0;
}