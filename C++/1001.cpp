/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-30 16:03
 * Filename :        1001.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
int a[10000+5];
int main(){
	int t,n,m,k;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n>>m>>k;
		int flag=0;
		for (int i=0;i<n;i++){
			cin>>a[i];
			if (a[i]>m)
				flag=1;
		}
		if (flag==0){
			cout<<"Case #"<<cas<<":"<<endl;
			cout<<"why am I so diao?"<<endl;
			continue;
		}
		flag=0;
		sort(a,a+n);
		for (int i=0;i<n;i++){
			int mm=a[i];
			int kk=
		}
		cout<<"Case #"<<cas<<":"<<endl;
		if (flag==0)
			cout<<"madan!"<<endl;
		else
			cout<<"why am I so diao?"<<endl;
	}

	return 0;
}
