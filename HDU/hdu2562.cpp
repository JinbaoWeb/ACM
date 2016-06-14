#include <iostream>
#include <string.h>
using namespace std;
char str[100];
int main(){
	int n;
	cin>>n;
	while (n--){
		cin>>str;
		int len=strlen(str);
		for (int i=0;i<len;i=i+2){
			char tmp=str[i];
			str[i]=str[i+1];
			str[i+1]=tmp;
		}
		cout<<str<<endl;
	}
	return 0;
}