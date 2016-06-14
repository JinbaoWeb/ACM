#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,a[4];
	while (cin>>n){
		if (n==0){
			cout<<"YES"<<endl;
			cout<<1<<endl<<1<<endl<<3<<endl<<3<<endl;
		}
		if (n==1){
			cin>>a[0];
			cout<<"YES"<<endl;
			cout<<a[0]+1<<endl<<3*a[0]-1<<endl<<3*a[0]<<endl;
		}
		if (n==2){
			cin>>a[0]>>a[1];
			sort(a,a+2);
			if (a[1]<=a[0]*3){
				cout<<"YES"<<endl;
				cout<<4*a[0]-a[1]<<endl;
				cout<<3*a[0]<<endl;
			}
			else{
				if ((a[0]+a[1])%4==0){
					cout<<"YES"<<endl;
					cout<<(a[0]+a[1])/4<<endl;
					cout<<(a[0]+a[1])/4*3<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}	
		}
		if (n==3){
			cin>>a[0]>>a[1]>>a[2];
			int flag=0;
			for (int i=a[2]+1;i<=1000000;i++){
				a[3]=i;
				sort(a,a+4);
				if ((a[0]+a[1]+a[2]+a[3])%4!=0 || (a[1]+a[2])%2!=0)
					continue;
				int k1=(a[0]+a[1]+a[2]+a[3])/4,k2=(a[1]+a[2])/2,k3=a[3]-a[0];
				if (k1==k2 && k2==k3){
					flag=1;
					cout<<"YES"<<endl;
					cout<<i<<endl;
					break;
				}
			}
			if (flag==0)
				cout<<"NO"<<endl;
		}
		if (n==4){
			cin>>a[0]>>a[1]>>a[2]>>a[3];
			sort(a,a+4);
			if ((a[0]+a[1]+a[2]+a[3])%4!=0 || (a[1]+a[2])%2!=0){
				cout<<"NO"<<endl;
			}
			else{
				int k1=(a[0]+a[1]+a[2]+a[3])/4,k2=(a[1]+a[2])/2,k3=a[3]-a[0];
				if (k1==k2 && k2==k3){
					cout<<"YES"<<endl;
				}	
				else
					cout<<"NO"<<endl;
			}
			
		}
	}
	return 0;
}