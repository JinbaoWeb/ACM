#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int n,x,l,r;
	while (cin>>n>>x){
		int t=0,flag=1;
		for (int i=0;i<n;i++){
			cin>>l>>r;
			int k=(l-flag)/x;
			flag+=k*x;
			//cout<<flag<<endl;
			t+=r-flag+1;
			flag=r+1;
		}
		cout<<t<<endl;
	}
	return 0;
}