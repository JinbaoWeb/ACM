#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
using namespace std;
struct point{
	int t,x;
}p[10000+5];
bool cmp(point a,point b){
	if (a.t<b.t)
		return true;
	return false;
}
int main(){
	int t,n;
	cin>>t;
	for (int cases=1;cases<=t;cases++){
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>p[i].t>>p[i].x;
		sort(p,p+n,cmp);
		double max=0;
		int last=0,time=0;
		for (int i=0;i<n;i++){
			if (p[i].t==0){
				last=p[i].x;
				continue;
			}
			double speed=(p[i].x-last)*1.0/(p[i].t-time);
			if (speed<0)
				speed=-speed;
			if (max<speed)
				max=speed;
			last=p[i].x;
			time=p[i].t;
		}
		cout<<"Case #"<<cases<<": "<<fixed<<setprecision(2)<<max<<endl;
	}
	return 0;
}