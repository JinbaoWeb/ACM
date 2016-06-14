/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-06-19 00:30
 * Filename :        308B.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll Pow(int n){
	ll ans=1;
	for (int i=1;i<=n;i++)
		ans=ans*10;
	return ans;
}
int main(){
	ll n;
	while (cin>>n){
		ll ans=0;
		ll k=n;
		int count=0;
		while (k){
			//cout<<"--------"<<endl;
			count++;
			k/=10;
		}
		ll s=9;
		for (int i=1;i<count;i++){
			ans=ans+s*i;
			s=s*10;
		}
		//cout<<ans<<endl;
		ll left=n-Pow(count-1)+1;
		//cout<<left<<endl;
		ans+=left*count;
		cout<<ans<<endl;
	}
    return 0;
}