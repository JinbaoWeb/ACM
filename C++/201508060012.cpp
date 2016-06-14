#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool a[1000000+10];
typedef long long ll;
int main(){
	ll n;
	char str;
	ll r;
	while (cin>>n){
		memset(a,false,sizeof(a));
		 ans=0;
		int num=0;
		while (n--){
			cin>>str>>r;
			if (str=='+'){
				if (num<ans){
					a[r]=true;
					num++;
				}
				else{
					num++;
					if (ans<num)
						ans=num;
					a[r]=true;
				}
			}
			else{
				if (a[r]==false){
					ans++;
				}
				else{
					num--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}