#include <iostream>
using namespace std;
int main(){
	int t,n,num[10];
	cin>>t;
	while (t--){
		cin>>n;
		if (n<=10)
			cout<<n<<endl;
		else{
			int k=0;
			while (n>0){
				num[k++]=n%10;
				n/=10;
			}
			for (int i=0;i<k-1;i++){
				if (num[i]>=5)
					num[i+1]++;
				num[i]=0;
			}
			while (k--)
				cout<<num[k];
			cout<<endl;
		}
	}
	return 0;
}
