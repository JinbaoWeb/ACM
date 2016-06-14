#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
long long gcd(long long x, long long y){
	if (!x || !y) 
		return x > y ? x : y;
	for (int t; t = x % y; x = y, y = t);
	return y;
}
int main(){
	long long t,x,y,k;
	cin>>t;
	while (t--){
		cin>>x>>y>>k;
		long long s=gcd(x,y),count=1;
		int flag=0;
		long long p=s;
		while (count!=k){
			if (p==1)
				break;
			for (long long kk=2;kk<=p;kk++){
				if (p%kk==0){
					count++;
					p/=kk;
					break;
				}
					
			}
		}
		if (count==k)
			cout<<p<<endl;
		if (count<k)
			cout<<-1<<endl;
		/*
		for (long long p=s;p>=1;p--){
			if (s%p==0)
			{
				count++;
			}	
			if (count==k){
				cout<<p<<endl;
				flag=1;
				break;
			}
		}
		if (flag==0)
			cout<<-1<<endl;*/
	}
	return 0;
}
