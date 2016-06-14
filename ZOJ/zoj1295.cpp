#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int t;
	char s[100];
	cin>>t;
	cin.getline(s,100);
	while(t--){
		cin.getline(s,100);
		int len=strlen(s);
		while (len--)
			cout<<s[len];
		cout<<endl;
	}
	return 0;
}
