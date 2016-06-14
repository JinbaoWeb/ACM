#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int h1,h2,a,b;
	while (cin>>h1>>h2){
		cin>>a>>b;
		int x1=h1;
		int x2=x1+8*a;
		int x3=x2-12*b;
		int x4=x3+4*a;
		if (h2>=h1){
			if (x1>=x4 && x2<h2){
				cout<<-1<<endl;
				continue;
			}
			if (x2>=h2){
				cout<<0<<endl;
				continue;
			}
			int h=12*(a-b);
			int ans=(h2-x2)/h+((h2-x2)%h==0?0:1);
			cout<<ans<<endl;
		}
		else{
			if (x3>h2 && x4>=x1){
				cout<<-1<<endl;
				continue;
			}
			if (x3<=h2){
				cout<<0<<endl;
				continue;
			}
			int h=12*(b-a);
			int ans=(x3-h2)/h+((x3-h2)%h==0?0:1);
			cout<<ans<<endl;
		}
	}

	return 0;
}