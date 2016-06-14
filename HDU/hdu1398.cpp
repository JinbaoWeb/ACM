#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[1000],b[1000];
int main(){
	int n;
	while (cin>>n&&n>0){
		for (int i=0;i<=n;i++){
			a[i]=1;
			b[i]=0;
		}
		for (int i=2;i<=n;i++){
			for (int j=0;j<=n;j++){
				for (int k=0;k+j<=n;k+=i*i)
					b[j+k]+=a[j];
			}
			for (int j=0;j<=n;j++){
				a[j]=b[j];
				b[j]=0;
			}

		}
		cout<<a[n]<<endl;
	}

	return 0;	
}
