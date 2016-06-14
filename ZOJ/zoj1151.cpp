#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int t,n;
	char s[10000];
	cin>>t;
	while (t--){
		cin>>n;
		cin.getline(s,10000);
		while (n--){
			cin.getline(s,10000);
			int len=strlen(s),i,j,flag=0;
			for (i=0;i<len;i++){
				for (j=i;j<len;j++){
					if (s[j]==' '||s[j]==0){
						break;
					}
				}
				int ss=i;
				i=j;
				while (j-->=ss){
					cout<<s[j];
				}
			}
			cout<<endl;
		}
	}
	return 0;
} 
