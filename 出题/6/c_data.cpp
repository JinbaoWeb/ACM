#include <bits/stdc++.h>
using namespace std;
int main(){
	int t=1;
	cout<<1<<endl;
	for (int i=0;i<1000-1;i++){
		int a=rand()%26;
		if (a==0)
			cout<<' ';
		else{
			char temp=a+'a';
			cout<<temp;
		}
	}
	cout<<endl;
	return 0;
}