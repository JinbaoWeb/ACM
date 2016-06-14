#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	t=rand()%100;
	cout<<t<<endl;
	while (t--){
		int n=rand()%1000;
		for (int i=0;i<n;i++){
			int x=rand()%26;
			int y=rand()%2;
			char s;
			if (y==0)
				s='a'+x;
			else
				s='A'+x;
			cout<<s;
		}
		cout<<endl;
	}

	return 0;
}