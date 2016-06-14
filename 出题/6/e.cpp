#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[1000];
int main(){
	char s[12]={'T','h','a','n','k','s','g','i','v',' ','D','y'};
	int a[20];
	int t;
	cin>>t;
	getchar();
	while (t--){
		cin.getline(str,1000);
		int len=strlen(str);
		memset(a,0,sizeof(a));
		for (int i=0;i<len;i++){
			for (int j=0;j<12;j++){
				if (s[j]==str[i]){
					a[j]++;
					break;
				}
			}
		}
		int ans=10000;
		for (int i=0;i<12;i++){
			ans=min(ans,a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}