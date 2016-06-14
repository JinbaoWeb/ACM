#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int a,n,num[100005];
	while (cin>>a>>n){
		if (n==0){
			cout<<0<<endl;
			continue;
		}
		memset(num,0,sizeof(num));
		int flag=0;
		for (int i=0;i<n;i++){
			num[i]=(n-i)*a+flag;
			flag=num[i]/10;
			num[i]%=10;
		}
		num[n]=flag;
		int index;
		for (int i=100004;i>=0;i--)
			if (num[i]!=0){
				index=i;
				break;
			}
		while (index>=0){
			cout<<num[index--];
		} 
		cout<<endl;
	}
	return 0;
} 
