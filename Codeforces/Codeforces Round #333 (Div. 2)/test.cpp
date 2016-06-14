#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 1000
int main(){
	int t;
	char s[N];
	cin>>t;
	getchar();
	while (t--){
		cin.getline(s,N);
		cout<<s<<endl;
	}
	return 0;
}