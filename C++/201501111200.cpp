#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;
using namespace std;
int main(){
	int t,n,a[12];
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		int count=0,flag=0;
		sort(a,a+n);
		while (a[0]!=a[n-1]){
			int k=a[n-1]-a[0];
			a[0]=a[n-1]=k;
			sort(a,a+n);
			count++;
			if (count>=200000000){
				flag=1;
				break;
			}
		}
		if (flag==0)
			cout<<a[0]<<endl;
		else
			cout<<"Nooooooo!"<<endl;
	}
	return 0;
}