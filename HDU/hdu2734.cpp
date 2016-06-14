#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char str[300];
int main(){
	while (1){
		cin.getline(str,300);
		if (strcmp(str,"#")==0)
			break;
		long long ans=0;
		int len=strlen(str);
		for (int i=1;i<=len;i++){
			if ('A'<=str[i-1] && str[i-1]<='Z'){
				ans+=i*(str[i-1]-'A'+1);
				//cout<<i<<" "<<str[i]<<" "<<i*(str[i]-'A'+1)<<endl;
			}
		}
		cout<<ans<<endl;
		//cin.getline(str,300);
	}

	return 0;
}