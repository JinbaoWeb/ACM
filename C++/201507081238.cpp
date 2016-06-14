#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
typedef long long ll;
int main(){
	ll x;
	double y;
	//ifstream cin("1.txt");
	while (cin>>x>>y){
		if (x>y){
			cout<<-1<<endl;
			continue;
		}

		ll ans=x-1;
		ll n=1;
		double p=1.0;
		double kk=1.0*p/n;//每一次的斜率
		double k=((y+0.999999)/x);	//最终的斜率
		for (int i=1;i<=x;i++){
			double pp=i*k;
			n=i;
			p=n*kk;
			cout<<n<<" "<<p<<endl;
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