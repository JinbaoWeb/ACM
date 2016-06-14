#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main(){
	double u,v,w,l;
	int t;
	cin>>t;
	while (cin>>u>>v>>w>>l){
		double ans=l*w/(u+v);
		//cout<<ans<<endl;
		printf("%.3f\n",ans);
	}

	return 0;
}