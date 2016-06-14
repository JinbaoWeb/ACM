/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-21 14:47
 * Filename :        poj3994.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll n0,n1,n2,n3,n4,s;
	int k=1;
	while (cin>>s&&s){
		n0=0;
		while (n0!=s){
			n0=s;
			n1=3*n0;
			if (n1%2==1){
	 			n2=(n1+1)/2;
				cout<<k<<". odd ";
			}
			else{
	 			cout<<k<<". even ";
				n2=n1/2;
			}
			n3=3*n2;
			n4=n3/9;
			cout<<n4<<endl;
			if (n1&1==0)
				n0=2*n4+1;
			else
				n0=2*n4;
			s=n0;
		}
		k++;
	}

	return 0;
}
