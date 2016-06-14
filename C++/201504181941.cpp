#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define Max 100000+3
int main(){
	int a[Max];
	int t,n,x;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n;
		int max=0;
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++){
			cin>>x;
			if (max<x)
				max=x;
			for (int i=1;i*i<=x;i++){
				if (x%i==0){
					a[i]++;
					if (x/i!=i)
						a[x/i]++;
				}
			}
		}
		int k;
		for (k=max;k>=1;k--){
			if (a[k]>1)
				break;
		}
		cout<<"Case #"<<cas<<": "<<k<<endl;
	}
	return 0;
}
