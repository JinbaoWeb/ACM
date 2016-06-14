/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-06-07 18:55
 * Filename :        1001.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
int main(){
	char str[105];
	int t;
	cin>>t;
	while (t--){
		cin>>str;
		int len=strlen(str);
		for (int i=0;i<len;i=i+2){
			cout<<str[i];
		}
		cout<<endl;
		for (int i=len-1;i>0;i=i-2)
			cout<<str[i];
		cout<<endl;
	}

	return 0;
}
