#include <iostream>
using namespace std;
#define MAX 200005
int main(){
	int n,k,a[MAX],b[MAX];
	while (cin>>n>>k){
		int sum=0,temp,s=0;
		for (int i=0;i<k;i++){
			cin>>a[i];
			sum+=a[i];
		}
		b[s++]=sum;
		for (int i=k;i<n;i++){
			cin>>a[i];
			sum=sum-a[i-k]+a[i];
			b[s++]=sum;
		}
		for (int i=0;i<s;i++)
			cout<<b[i]<<" ";
		cout<<endl;
		int max=0;
		for (int i=0;i<s;i++){
			for (int j=i+k;j<s;j++){
				sum=b[i]+b[j];
				if (sum>max)
					max=sum;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
