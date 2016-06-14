#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll a[1005];
ll maxsequence(ll a[], int len){
    ll maxsum, maxhere;
    maxsum = maxhere = a[0];   
    for (int i=1; i<len; i++) {
        if (maxhere <= 0)
            maxhere = a[i];  
        else
            maxhere += a[i]; 
        if (maxhere > maxsum)
            maxsum = maxhere; 
    }
    return maxsum;
}

int main(){
	int t,n,p;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&p);
		for (int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		ll max=-0xffffffff;
		for (int i=0;i<n;i++){
			ll temp=a[i];
			a[i]=p;
			ll t=maxsequence(a,n);
			if (max<t)
				max=t;
			a[i]=temp;
		}
		cout<<max<<endl;
	}
	return 0;
}