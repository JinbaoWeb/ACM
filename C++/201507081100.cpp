#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll x;
	double y;
	while (cin>>x>>y){
		if (x>y){
			cout<<-1<<endl;
			continue;
		}

		ll ans=x-1;
		ll n=1;
		double p=1.0;
		double kk=p/n;
		double k=(y+1)/x;
		for (int i=1;i<=x;i++){
			double pp=i*k;
			//if (pp>=y)
				//break;
			n=i;
			p=n*kk;
			cout<<n<<" "<<p<<endl;
			//cout<<"text: "<<p<<" "<<pp<<endl;
			ll temp=(pp-p);
			//cout<<temp<<"-------"<<endl;
			ans+=temp;
			p=p+temp;
			kk=p/n;
			cout<<n<<" "<<p<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}