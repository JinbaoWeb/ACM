#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX = 1000010;
int p[MAX],count;
void fun(ll n){
	ll i;
	count=0;
	for (i=2;i*i<=n;i++){
		if (n%i==0){
			p[count++]=i;
			while (n%i==0)
				n/=i;
		}
	}
	if (n>1)
		p[count++]=n;
}
ll solve(ll n,ll r){
	ll sum=0;
	for (int i=1;i<(1<<count);i++){
		ll mult=1,bits=0;
		for (int j=0;j<count;j++){
			if (i&(1<<j)){
				bits++;
				mult*=p[j];
			}
		}
		ll cur=r/mult;
		if (bits%2==1)
			sum+=cur;
		else
			sum-=cur;
	}
	return r - sum;
}
int main(){
	ll n,m,mid,num;
	while (cin>>n>>m){
		fun(n);
		ll r=0xffffffff,l=1;
		while (r-l>0){
			mid=(r+l)/2;
			num=solve(n,mid);
			if (num>=m)
				r=mid;
			else
				l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}