//三角形的性质：三角形的任何两边的和一定大于第三边,三角形的任意两边的差一定小于第三边
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream cin("a.in");
	ofstream cout("a.out");
	int t,a,b,c;
	cin>>t;
	while (t--){
		cin>>a>>b>>c;
		int Max=max(a,max(b,c)),Min=min(a,min(b,c));
		int Mid=a+b+c-Max-Min;
		if (Max<Min+Mid){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}