#include <bits/stdc++.h>
using namespace std;
int main(){
	char str[]={"Thanksgiving Day"};
	int t=rand()%100;
	cout<<1<<endl;
	//while (t--){
		int n=rand()%999+1;
		for (int i=0;i<n;i++){
			int x=rand()%16;
			cout<<str[x];
		}
		cout<<endl;
	//}
	return 0;
}