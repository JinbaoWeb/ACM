#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	int t,n,a[401],x,y;
	cin>>t;
	while (t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++){
			cin>>x>>y;
			if (x>y){
				int temp=x;
				x=y;
				y=temp;
			}
			if (x%2!=0)
				x++;
			if (y%2!=0)
				y++;
			for (int j=x;j<=y;j+=2)
				a[j]++;
		}
		sort(a,a+401);
		cout<<a[400]*10<<endl;
	}
	return 0;
}