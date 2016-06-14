
#include <iostream>
using namespace std;
int totalOne(int x){
	int count = 0;
	while(x){
		x = x & ( x - 1 );
		count++;
	}
	return count;
}
int main(){
	int n,a;	
	while (cin>>n){
		int max=0,num=0,min=0xffffff;
		for (int i=0;i<n;i++){
			cin>>a;
			num=totalOne(a);
			if (num<min){
				max=a;
				min=num;
			}
			if (num==min&&max>a)
				max=a;	
		}
		cout<<max<<endl;
	}
	return 0;
}
