#include <iostream>
#include <algorithm>
using namespace std;
bool istrue(int n){
	if (999<n&&n<10000){
		int last=n%10,a;
		n/=10;
		while (n>0){
			a=n%10;
			if (a!=last)
				return true;
			n/=10;
		}
		return false;
	}
	else
		return false;
}
int main(){
	int n,num[4];
	while (cin>>n){
		if (n==-1)
			break;
		cout<<"N="<<n<<":"<<endl;
		if (istrue(n)==false)
			cout<<"No!!"<<endl;
		else{
			int count=0;
			while (1){
				int k=0;
				while (n>0){
					num[k++]=n%10;
					n/=10;
				}
				sort(num,num+k);
				int k1=0,k2=0;
				for (int i=0;i<k;i++){
					k1=k1*10+num[i];
					k2=k2*10+num[k-1-i];
				}
				n=k2-k1;
				count++;
				cout<<k2<<"-"<<k1<<"="<<n<<endl;
				if (n==0||n==6174){
					cout<<"Ok!! "<<count<<" times"<<endl;
					break;
				}
			}
			
			
		}
	}
	return 0;
}
