#include <iostream>
#include <string.h>
using namespace std;
int m[100000+5];
int main(){
	int n,k,mm;
	while (cin>>n>>k){
		int ans=0;
		int kk=k;
		while (k--){
			cin>>mm;
			for (int i=0;i<mm;i++)
				cin>>m[i];
			int li=m[0];
			for (int i=1;i<mm;i++){
				if (m[i]==li+1)
					li=m[i];
				else{
					kk++;
					li=m[i];
					ans++;
				}
			}
		}
		//cout<<ans<<endl;
		cout<<ans+kk-1<<endl;
	}
	return 0;
}