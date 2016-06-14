#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[2][2],b[2][2];
	int t;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		for (int i=0;i<2;i++){
			for (int j=0;j<2;j++)
				cin>>a[i][j];
		}
		for (int i=0;i<2;i++){
			for (int j=0;j<2;j++)
				cin>>b[i][j];
		}
		int flagflag=0;
		for (int k=0;k<4;k++){
			int temp=a[0][0];
			a[0][0]=a[1][0];
			a[1][0]=a[1][1];
			a[1][1]=a[0][1];
			a[0][1]=temp;
			int flag=0;
			for (int i=0;i<2;i++){
				for (int j=0;j<2;j++)
					if (a[i][j]!=b[i][j]){
						flag=1;
						break;
					}
			}
			if (flag==0){
				flagflag=1;
				break;
			}
		}
		cout<<"Case #"<<cas<<": ";
		if (flagflag==0)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<"POSSIBLE"<<endl;
	}
	return 0;
}