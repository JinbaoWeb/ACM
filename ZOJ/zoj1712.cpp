/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-08 11:14
 * Filename :        zoj1712.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <string.h>
using namespace std;
char str[10000];
int a[32];
void init(){
	int ans=2;
	for (int i=1;i<=32;i++){
		a[i]=ans-1;
		ans=ans*2;
	}
}
int main(){
	init();
	while (cin>>str){
		if (strcmp(str,"0")==0)
			break;
		int len=strlen(str);
		long long ans=0;
		for (int i=1;i<=len;i++){
		//	cout<<a[i]<<" ";
			ans+=a[i]*(str[len-i]-'0');
	//		cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}

	return 0;
}
