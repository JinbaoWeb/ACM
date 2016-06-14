#include <iostream>
using namespace std;
int x[]={1000,1500,2000,2500};
int main(){
	int t,a,b;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		int ans=0;
		for (int i=0;i<4;i++){
			cin>>a>>b;
			int k=x[i]*(250-a)/250-50*b;
			if (k<x[i]*4/10)
				k=x[i]*4/10;
			ans+=k;
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}