#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,a,p,b,q;
	t=rand()%100+1;
	cout<<t<<endl;
	while (t--){
		int s=rand()%4+1;
		p=rand()%8+2;
		q=rand()%8+2;
		int f1=0;
		for (int i=0;i<s;i++){
			a=rand()%p;
			if (a==0 && f1==0)
				a++;
			f1=1;
			cout<<a;
		}
		cout<<" "<<p<<" ";
		int s2=rand()%4+1;
		int f2=0;
		for (int i=0;i<s2;i++){
			b=rand()%q;
			if (b==0 && f2==0)
				b++;
			f2=1;
			cout<<b;
		}
		cout<<" "<<q<<endl;
	}
	return 0;
}