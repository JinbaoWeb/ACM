/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-09 19:00
 * Filename :        A.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		int min=0xffffff;
		for (int i=1;i*i<=n;i++){
			if (n%i==0){
			//	cout<<i<<endl;
				int ans=2*(i+n/i);
			//	cout<<ans<<endl;
				if (ans<min)
					min=ans;
			}
		}
		cout<<min<<endl;
	}

	return 0;
}
