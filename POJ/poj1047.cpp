#include <iostream>
#include <string.h>
using namespace std;
char s[100];
int a[100];
int main(){
	while (cin>>s){
		int len=strlen(s);
		memset(a,0,sizeof(a));
		int k=0,left=0;
		for (int i=len-1;i>=0;i--){
			int ans=(s[i]-'0')*(len+1)+left;
			a[k++]=ans%10;
			left=ans/10;
		}
		while (left!=0){
			a[k++]=left%10;
			left/=10;
		}
		int flag=0;
		for (int i=0;i<k;i++){
			if (a[i]!=9){
				flag=1;
				break;
			}
		}
		if (flag==1)
			cout<<s<<" is not cyclic"<<endl;
		else
			cout<<s<<" is cyclic"<<endl;
	}
	return 0;
}