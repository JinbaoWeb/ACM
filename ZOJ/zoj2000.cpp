#include <iostream>
using namespace std;
typedef long long ll;
ll pow(int a,int b){
	ll ans = 1;
	for (int i=0;i<b;i++){
		ans*=a;
	}
	return ans;
}
int main(){
	ll n;
	while (cin>>n&&n){
		int count=1;
		int q=9;
		while (n>q){
			n-=q;
			count++;
			if (n>q){
				n-=q;
				count++;
			}
			else
				break;
			q*=10;
		}
		//cout<<"n="<<n<<endl;
		int k=(count-1)/2;
		//cout<<"k="<<k<<endl;
		ll ans=pow(10,k)+n-1;
		//cout<<"ans="<<ans<<endl;
		//cout<<"count="<<count<<endl;
		int a[20],s=0;
		cout<<ans;
		while (ans){
			a[s++]=ans%10;
			ans/=10;
		}
		for (int j=count/2-1;j>=0;j--){
			if (j<0)
				break;
			cout<<a[s-1-j];
		}
		cout<<endl;
	}
	return 0;
}