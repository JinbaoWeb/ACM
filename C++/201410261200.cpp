#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
	int t;
	long long n;
	scanf("%d",&t);
	while (scanf("%lld",&n)!=EOF){
		long long sum=1;
		for (int i=0;i<n;i++){
			sum*=2;
			if (sum>=(1e9+7))
				sum-=(1e9+7);
		}
		printf("%lld\n",sum-1);
		//cout<<sum-1<<endl;
	}
	return 0;
} 
