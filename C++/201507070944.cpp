#include <iostream>
using namespace std;
int gcd(int x, int y){
if (!x || !y) return x > y ? x : y;
for (int t; t = x % y; x = y, y = t);
return y;
}
int c(int a,int k){
	int ans=0;
	while (a%k==0){
		a/=k;
		ans++;
	}
	return ans;
}
int main(){
	int a,b;
	while (cin>>a>>b){
		int k=gcd(a,b);
		int x=a/k,y=b/k;
		int count_a=0,count_b=0;
		while (x%2==0){
			x/=2;
			count_a++;
		}
		while (x%3==0){
			x/=3;
			count_a++;
		}
		while (x%5==0){
			x/=5;
			count_a++;
		}

		while (y%2==0){
			y/=2;
			count_b++;
		}
		while (y%3==0){
			y/=3;
			count_b++;
		}
		while (y%5==0){
			y/=5;
			count_b++;
		}
		if (x==y){
			cout<<count_a+count_b<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}