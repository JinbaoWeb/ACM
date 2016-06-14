#include <iostream>
#include <string.h>
using namespace std;
int main(){
	char s[100];
	while (cin>>s){
		if (strcmp(s,"*")==0)
				break;
		int len=strlen(s),flag=0;
		for (int i=0;i<len;i++){
			for (int j=i+1;j<len;j++){
				if (s[i]==s[j]){
					for (int k=1;k<len-j;k++){
						if (s[k+i]==s[k+j]){
							flag=1;
							goto A;
						}
					}
				}
			}
		}
		A:
		if (flag==0)
			cout<<s<<" is surprising."<<endl;
		else
			cout<<s<<" is NOT surprising."<<endl;
	}
	return 0;
}