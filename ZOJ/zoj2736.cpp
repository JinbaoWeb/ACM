#include <iostream>
#include <cmath>
using namespace std;
int main(){
	long long a,b;
	while (cin>>a){
		long long w=a;
     	b=0;
     	while (a){
        	long long ans=a%10;
        	a/=10;
        	b+=ans*ans*ans;
     	}
     	if (w==b)
     		cout<<"Yes"<<endl;
     	else
     		cout<<"No"<<endl;
	}
return 0;
}