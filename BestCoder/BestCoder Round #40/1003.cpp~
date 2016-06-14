/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-09 19:19
 * Filename :        1003.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll x1,y1,x2,y2,p;
	while (cin>>x1>>y1>>x2>>y2>>p){
		ll ans1=0;
		ll k=1;
		if (y1+1>x1){
			k=0;
		}
		else{
			for (ll i=0;i<y1;i++)
				k=k*(x1-i)/(i+1)%p;
		}
		for (ll i=y1;i<y2+1;i++){
			if (i>x1){
				k=0;
				break;
			}
			k=k*(x1-i)/(i+1)%p;
			ans1+=k;
			ans1=ans1%p;
		}

		ll ans2=0;
		ll k2=1;
		if (y1+1>x2+1)
			k2=0;
		else{
			for (ll i=0;i<y1;i++)
				k2=k2*(x2+1-i)/(i+1)%p;
		}
		for (ll i=y1;i<y2+1;i++){
			if (i>x2+1){
				k2=0;
				break;
			}
			k2=k2*(x2+1-i)/(i+1)%p;
			ans2+=k2;
			ans2%=p;
		}
		cout<<(ans2-ans1+p)%p<<endl;
	}
	return 0;
}
