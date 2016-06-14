/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-30 14:26
 * Filename :        1003.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
int a[100000+5];
int abs(int x){
	if (x>0)
		return x;
	return -x;
}
int main(){
	int t,n;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n;
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		if (n<3){
			cout<<"Case #"<<cas<<": "<<endl;
			cout<<0<<endl;
			continue;
		}
		int min=0;
		for (int i=1;i<n-1;i++){
			if (a[i]>=a[i-1])
				continue;
			if (abs(a[i]-a[i-1])<abs(a[i+1]-a[i])){
				if (min<abs(a[i]-a[i-1]))
					min=abs(a[i]-a[i-1]);
				a[i]=a[i-1];
			}
			else{
				if (min<abs(a[i]-a[i+1]))
					min=abs(a[i]-a[i+1]);
				a[i]=a[i+1];
			}
		}
		if (a[n-1]<a[n-2]){
			if (min<abs(a[n-1]-a[n-2]))
				min=abs(a[n-1]-a[n-2]);
			a[n-1]=a[n-2];
		}
		cout<<"Case #"<<cas<<": "<<endl;
		cout<<min<<endl;
	}

	return 0;
}
