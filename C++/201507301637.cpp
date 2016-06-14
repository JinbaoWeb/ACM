#include <iostream>
using namespace std;
int main(){
	int k;
	while (cin>>k){
		if (k<=100000){
			cout<<k<<endl;
			for (int i=0;i<k-1;i++){
				cout<<1<<" ";
			}
			cout<<1<<endl;
		}
		else{
			int i,j;
			for (i=1;i<k;i++){
				if ((k-i)%(i+1)==0)
					break;
			}
			j=(k-i)/(i+1);
			for (int s=0;s<i;s++)
				cout<<1<<" ";
			for (int s=0;s<j-1;s++)
				cout<<2<<" ";
			cout<<2<<endl;
		}
	}
	
	return 0;
}