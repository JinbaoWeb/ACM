#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
char s[1000000+5],t[1000000+5];
int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>s>>t;
		int len=strlen(s);
		for (int i=len-1;i>=0;i--){
			if (t[i]!=s[len-1])
				cout<<0;
			else{
				int ii=i,jj=len-1;
				int flag=0;
				while (ii>=0&&jj>=0){
					if (t[ii--]!=s[jj--]){
						flag=1;
						break;
					}
				}
				if (flag==0)
					cout<<1;
				else
					cout<<0;
			}
		}
	}
	return 0;
}