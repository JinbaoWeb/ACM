#include <iostream>
using namespace std;
int gcd(int x, int y){
if (!x || !y) return x > y ? x : y;
for (int t; t = x % y; x = y, y = t);
return y;
}
int main(){
	int t,n;
	
	while (cin>>n){
		int sum=0;
		while (n--){
			cin>>t;
			int flag=0;
			for (int i=2;i<t;i++){
				if (gcd(i,t)>1)
				{
					flag=1;
					
				}
			}
			if (flag==0)
				sum+=t;
		}
		cout<<sum<<endl;
	}
	return 0;
}