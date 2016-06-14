#include <iostream>
using namespace std;
bool isprime(int n){
	if (n==2||n==3||n==5||n==7)
		return true;
	for (int i=2;i*i<=n;i++)
		if (n%i==0)
			return false;
	return true;
}
int main(){
	int n,x,y,a[4];
	cin>>n;
	while (n--){
		cin>>x>>y;
		if (x==y){
			cout<<0<<endl;
			continue;
		}
		int k=3;
		while (x){
			a[k--]=x%10;
			x/=10;
		}
		int count=0,flag=0;
		for (int i=0;i<4;i++){
			for (int j=0;j<10;j++){
				if (a[i]==j)
					continue;
				int temp=a[i];
				count++;
				a[i]=j;
				x=a[0]*1000+a[1]*100+a[2]*10+a[3];
				if (isprime(x)==false){
					a[i]=temp;
					continue;
				}	
				cout<<x<<endl;
				if (x==y){
					cout<<count<<endl;
					flag=1;
					break;
				}
				
			}
			if (flag==1)
				break;
		}
	} 
	return 0;
}
