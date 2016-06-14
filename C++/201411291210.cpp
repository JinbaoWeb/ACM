#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
#define MAX 1000005
int main(){
	int t,n,index;
	short a[MAX];
	cin>>t;
	for (int csa=1;csa<=t;csa++){
		cin>>n;
		memset(a,-1,sizeof(a));
		for (int j=0;j<n;j++){
			cin>>index;
			cin>>a[index];
		}
		double max=0;
		int last=0,time=0;
		for (int i=1;i<MAX;i++){
			if (a[i]==-1)
				continue;
			double speed=(a[i]-last)*1.0/(i-time);
			//cout<<i-time<<"------------"<<endl;
			if (speed<0)
				speed=-speed;
			if (speed>max)
				max=speed;
			last=a[i];
			time=i;
		}
		cout<<"Case #"<<csa<<": "<<fixed<<setprecision(2)<<max<<endl;
	}
	return 0;
}