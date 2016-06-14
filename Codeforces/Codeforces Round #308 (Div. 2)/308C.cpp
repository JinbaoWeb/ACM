/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-06-20 01:00
 * Filename :        308C.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int Count(ll w,ll m){
	ll k=1;
	int i=1;
	for (i=1;;i++){
		if (k>m)
			break;
		k=w*k;
	}
	return i;
}
ll Pow(ll w,int k){
	ll ans=1;
	for (int i=1;i<k;i++)
		ans*=w;
	return ans;
}
int main(){
	ll w,m;
	while (cin>>w>>m){
		int flag=0,k;
		ll s=m;
		while (m){
			ll temp=1;
			for (k=1;temp<m;k++)
				temp=temp*w;
			cout<<temp<<endl;
			s=min(m-temp/w+1,temp-m);

			if (s==m-temp/w+1)
				s--;
			cout<<s<<endl;
			if (s==m){
				flag=1;
				break;
			}
			m=s;
		}
		if (flag==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}