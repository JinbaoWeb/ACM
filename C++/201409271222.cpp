#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
double mod(double a,double b){
	double k=int(a/b);
	return a-k*b;
}
double gcd(double x, double y){
	if (!x || !y) return x > y ? x : y;
	for (double t; t = mod(x,y); x = y, y = t);
	return y;
}
int main(){
	char a[10005],b[10005];
	int t;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>a>>b;
		double x=0,y=0;
		int len_a=strlen(a),k=0,len_b=strlen(b);
		while (len_a-->0){
			x+=pow(2,k)*(a[len_a]-'0');
			k++;
		} 
		k=0;
		while (len_b-->0){
			y+=pow(2,k)*(b[len_b]-'0');
			k++;
		}
		cout<<x<<"-"<<y<<endl;
		double answer=gcd(x,y);
		cout<<answer<<endl;
		//cout<<"Case #"<<cas<<": ";
		int map[10005],p=0;
		while (answer>0){
			map[p++]=mod(answer,2);
			answer=int(answer/2);
		}
		while (p-->0){
			cout<<map[p];
		}
		cout<<endl;
	}
	return 0;
} 
