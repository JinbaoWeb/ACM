/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-02 12:47
 * Filename :        201505021230.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <string.h>
using namespace std;
struct s{
	int l,r,ans;
}t[1005];
int gcd(int x, int y){
	if (!x || !y) return x > y ? x : y;
	for (int t; t = x % y; x = y, y = t);
	return y;
}
int lcm(int x,int y){
	int k=gcd(x,y);
	return x/k*y;
}
int main(){
	int tt,n,q,l,r,ans;;
	int a[1005];
	cin>>tt;
	while (tt--){
		cin>>n>>q;
		int flag=0;
		for (int i=1;i<=n;i++)
			a[i]=1;
		for (int i=0;i<q;i++){
			cin>>t[i].l>>t[i].r>>t[i].ans;
			for (int j=t[i].l;j<=t[i].r;j++){
				a[j]=lcm(a[j],t[i].ans);
			}
		}
		for (int i=0;i<q;i++){
			int s=a[t[i].l];
			for (int j=t[i].l+1;j<=t[i].r;j++){
				s=gcd(s,a[j]);
			}
			if (s!=t[i].ans){
				flag=1;
				break;
			}
		}
		if (flag==1)
			cout<<"Stupid BrotherK!"<<endl;
		else{
		//	cout<<"-----22---"<<n<<endl;
			for (int i=1;i<n;i++)
				cout<<a[i]<<" ";
			cout<<a[n]<<endl;
		}
	}

	return 0;
}
