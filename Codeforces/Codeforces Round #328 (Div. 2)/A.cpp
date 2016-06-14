#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[10][10];
int main(){
	for (int i=0;i<8;i++)
		cin>>s[i];
	int w=10,b=10;
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			if (s[i][j]=='W'){
				int flag=0;
				for (int k=0;k<i;k++){
					if (s[k][j]=='B'){
						flag=1;
						break;
					}
				}
				if (flag==0)
					w=min(w,i);
			}
			if (s[i][j]=='B'){
				int flag=0;
				for (int k=i+1;k<8;k++){
					if (s[k][j]=='W'){
						flag=1;
						break;
					}
				}
				if (flag==0)
					b=min(b,8-i-1);
			}
		}
	}
	//cout<<w<<" "<<b<<endl;
	if (w>b){
		cout<<"B\n";
	}
	else
		cout<<"A"<<endl;
	return 0;
}