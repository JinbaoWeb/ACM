#include <iostream>
using namespace std;
#define MAX 1000005
int main(){
	int n,t;
	short a[MAX];
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		int count=0;
		int s=n;
		while (n){
			int flag=0,index=0,flagflag=0;
			for (int i=0;i<s;i++){
				if (a[i]==n){
					flag=1;
					index=i;
					continue;
				}
				if (flag==0)
					continue;
				if (a[i]<n){
					
					int temp=a[index];
					a[index]=a[i];
					a[i]=temp;
					flagflag=1;
					index=i;
				}
			}
			if (flagflag==1)
				count++;
			n--;
		}
		cout<<"Case #"<<cas<<": "<<count<<endl;
	}
	return 0;
}