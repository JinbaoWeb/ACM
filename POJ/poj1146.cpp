#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	char s[100];
	while (cin>>s){
		int n=strlen(s);
		if (strcmp(s, "#") == 0)
            break;
        if (next_permutation(s, s + n))
            cout<<s<<endl;
        else
            cout<<"No Successor\n";
	}
	return 0;
}