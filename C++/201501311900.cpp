#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
	int n,t,a;
	bool used[1003];
	cin>>t;
	while (t--){
		cin>>n;
		memset(used,false,sizeof(used));
		for (int i=0;i<n;i++){
			cin>>a;
			used[a]=true;
		}
		int flag=0;
		for (int i=1;i<=n+2;i++){
			if (used[i]==false){
				flag++;
				if (flag==1)
					cout<<i<<" ";
				if (flag==2)
					cout<<i<<endl;
			}
		}
	}
	return 0;
}