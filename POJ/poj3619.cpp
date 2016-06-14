#include <iostream>
using namespace std;
int main(){
	int n,k,s,t,r;
	cin>>n>>k;
	for (int i=0;i<k;i++){
		cin>>s>>t>>r;
		int page=n;
		int time=0;
		while (page>s*t){
			time=time+t+r;
			page-=s*t;
		}
		time+=page/s;
		if (page%s)
			time++;
		cout<<time<<endl;
	}
	return 0;
}