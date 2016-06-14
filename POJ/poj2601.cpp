#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 3005
int main(){
	int n;
	double a0,an;
	double c[MAX];
	while (cin>>n){
		cin>>a0>>an;
		double ans=0;
		for (int i=0;i<n;i++){
			cin>>c[i];
			ans+=2*(n-i)*c[i];
		}
		ans=(n*a0+an-ans)/(n+1);
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
	return 0;
}