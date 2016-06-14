/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-01 19:16
 * Filename :        201505011915.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int p[20];
int main(){
	int t,c,n,x;
	cin>>t;
	while (t--){
		cin>>c>>n;
		memset(p,0,sizeof(p));
		for (int i=0;i<n;i++){
			cin>>x;
			p[x]++;
		}
		int i=20;
		while (i--){
			if (p[i]!=0)
				break;
		}
	//	cout<<p[i]<<" "<<i<<"------"<<endl;
		cout<<c/p[i]<<endl;
	}

	return 0;
}
