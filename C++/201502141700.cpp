#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAX_INT 2147483647 

int main(){
	ll a[102];
	int count[102];
	int n,flag=1,x,k;
	while (cin>>n){
		k=0;
		for (int i=0;i<102;i++)
			count[i]=1;
		for (int i=0;i<n;i++){
			cin>>x;
			int f=0;
			for (int j=0;j<k;j++){
				if (a[j]==x){
					count[j]++;
					f=1;
					break;
				}
			}
			if (f==0){
				a[k]=x;
				k++;
			}
		}
		for (int i=0;i<k;i++){
			for (int j=i;j<k;j++){
				if (a[i]>a[j]){
					ll temp=a[i];
					a[i]=a[j];
					a[j]=temp;
					int t=count[i];
					count[i]=count[j];
					count[j]=t;
				}
			}
		}
		ll ans=0;
		if (k==1){
			cout<<"Case #"<<flag<<": "<<-1<<endl;
			flag++;
			continue;
		}
		for (int i=0;i<k;i++){
			if (i==0){
				if (a[n-1]+a[i]==a[i+1])
					ans+=count[i];
			}
			else{
				if (i==n-1){
					if (a[n-2]+a[n-1]==a[0])
						ans+=count[i];
				}
				else{
					if (a[i-1]+a[i]==a[i+1])
						ans+=count[i];
				}
			}
		}
		cout<<"Case #"<<flag<<": "<<ans<<endl;
		flag++;
	}
	return 0;
}