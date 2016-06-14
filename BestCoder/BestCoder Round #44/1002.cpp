/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-06-07 19:36
 * Filename :        1002.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
ll a[100000+5];
ll sum(int l,int r,ll p){
	ll ans=p-a[r];
	if (ans<=a[l])
		return a[l]-ans;
	return a[l]+a[r];
}
int main(){
	int n;
	ll p;
	while (~scanf("%d%lld",&n,&p)){
		for (int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			a[i]%=p;
		}
		sort(a,a+n);
		ll Max=0;
		int l=0,r=n-1;
		while (l<r){
			ll k=sum(l,r,p);
		//	cout<<l<<"  "<<r<<"  "<<k<<endl;
			if (Max<k)
				Max=k;
			if (k<p/2)
				l++;
			else
				r--;
		}
		printf("%lld\n",Max);
	}
	return 0;
}
