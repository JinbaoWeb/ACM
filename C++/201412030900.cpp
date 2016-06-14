#include <iostream>
using namespace std;
#define MAX 100000+5
int main(){
	int a[MAX],n,last,x,now;
	while (cin>>n){
		if (n==1){
			cin>>x;
			cout<<0<<endl;
		}
		else if (n==2){
			cin>>last>>now;
			if (last>now)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
		else{
			int count = 0;
			cin>>last>>now;
			for (int i=2;i<n;i++){
				cin>>x;
				if ((last<=now&&now<=x)==false){
					count++;
					now=x;
				}
				last=now;
				now=x;
			}
			cout<<count<<endl;
		}
	}
	return 0;
}