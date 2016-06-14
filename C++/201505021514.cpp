/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-02 15:14
 * Filename :        201505021514.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define mod 4294967296
struct ar{
	ll x,y;
}array[100];
bool cmp(ar xx,ar yy){
	if (xx.x<yy.x)
		return true;
	else{
		if (xx.x==yy.x){
			if (xx.y<yy.y)
				return true;
			return false;
		}
		return false;
	}
}
int main(){
	ll n,l,r,a,b,c,d,t;
	cin>>t;
	while (t--){
		cin>>n>>l>>r>>a>>b>>c>>d;
		if (n<3)
			cout<<"NO"<<endl;
		else if (n>100)
			cout<<"YES"<<endl;
		else{
			array[0].x=l;
			array[0].y=r;
			for (ll i=1;i<n;i++){
				ll xx=(array[i-1].x*a+b)%mod;
				ll yy=(array[i-1].y*c+d)%mod;
				if (xx>yy){
					ll temp=xx;
					xx=yy;
					yy=temp;
				}
				array[i].x=xx;
				array[i].y=yy;
			}
			sort(array,array+n,cmp);
			int flag=0;
			for (ll i=0;i<n;i++){
				for (ll j=i+1;j<n;j++){
					for (ll k=j+1;k<n;k++){
						if (array[i].y<array[j].x && array[j].y<array[k].x){
							cout<<"YES"<<endl;
							flag=1;
							break;
						}
					}
					if (flag==1)
						break;
				}
				if (flag==1)
					break;
			}
			if (flag==0)
				cout<<"NO"<<endl;
		}
	}

	return 0;
}
