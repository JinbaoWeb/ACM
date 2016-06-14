#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll a,b;
	while (cin>>a>>b){
		if (a<b){
			ll temp=b;
			b=a;
			a=temp;
		}
		ll count=0;
		while (a!=b){
			if (a%b==0)
				break;
			ll max=a-b>b?a-b:b;
			ll min=a-b>b?b:a-b;
			a=max,b=min;
			count++;
		}
		cout<<a/b<<endl;
		if (a%b==0)
			count+=a/b-1;
		cout<<count+1<<endl;
	}
	return 0;
}