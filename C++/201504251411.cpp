#include <iostream>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while (t--){
		int x=1928;
		int d=1;
		cin>>n;
		for (int i=1929;i<=n;i++){
			int num=365;
			if (i%400==0 || (i%4==0&&i%100!=0))
				num++;
			int k=num%7;
			d+=k;
			d%=7;
		}
	
		if (d==0)
			cout<<9<<endl;
		else if (d==6 || d==1)
			cout<<6<<endl;
		else
			cout<<5<<endl;
	}
	return 0;
}
