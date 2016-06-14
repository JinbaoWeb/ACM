#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll x1,x2,y1,y2,a,b,c;
	int n;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	int count=0;
	for (int i=0;i<n;i++){
		cin>>a>>b>>c;
		if (((a*x1+b*y1+c)<0&&(a*x2+b*y2+c)>0)||((a*x1+b*y1+c)>0&&(a*x2+b*y2+c)<0))
			count++;
	}
	cout<<count<<endl;
	return 0;
}