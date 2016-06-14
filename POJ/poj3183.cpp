#include <iostream>
using namespace std;
int main(){
	int n,a,b,c;
	while (cin>>n){
		a=0,b=0,c=0;
		int flag=0;
		if (n<4){
			if (n==1){
				cin>>a;
				cout<<1<<endl;
			}
			if (n==2){
				cin>>a>>b;
				if (a==b)
					cout<<2<<endl;
				else
					cout<<1<<endl;
			}
			if (n==3){
				cin>>a>>b>>c;
				if (a==b && b==c)
					cout<<3<<endl;
				else if ((a<b && b<c)||(a>b && b>c)||(a<b && b>c))
					cout<<1<<endl;
				else
					cout<<2<<endl;
			}
			continue;
		}
		for (int i=1;i<=n;i++){
			cin>>c;
			if (a<=b && b>=c)
				cout<<i-1<<endl;
			a=b;
			b=c;
		}
	}
	return 0;
}