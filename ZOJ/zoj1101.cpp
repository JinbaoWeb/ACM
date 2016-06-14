#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int a[1005];
	while (cin>>n&&n){
		for (int i=0;i<n;i++){
			cin>>a[i];
			if (a[i]<0)
				a[i]=-a[i];
		}
			
		sort(a,a+n);
		int s=n;
		int flag=0,sum;
		while (n--){
			for (int i=0;i<s;i++){
				for (int j=i+1;j<s;j++){
					for (int k=j+1;k<s;k++){
						sum=a[i]+a[j]+a[k];
						if (sum==a[n]){
							cout<<sum<<endl;
							flag=1;
							break;
						}
						if (sum>a[n])
							break;	
					}
					if (flag)
						break;
				}
				if (flag)
					break;
			}
			if (flag)
				break;	
					
		}
		if (flag==0)
			cout<<"no solution"<<endl;
	}
	return 0;
} 
