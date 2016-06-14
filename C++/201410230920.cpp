#include <iostream>
using namespace std;
#define MAX 300+1
int main(){
	int n;
	char map[MAX][MAX];
	while (cin>>n){
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				cin>>map[i][j];
		char a=map[0][0],b=map[0][1];
		int flag=0;
		if (a==b)
			flag=1;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (i==j||j==n-1-i){	//对角线上的判断 
					if (map[i][j]!=a){
						flag=1;
						break;
					}
				}
				else{
					if (map[i][j]!=b){
						flag=1;
						break;
					}
				}
			}
			if (flag)
				break;
		}
		if (flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;	
	}
	return 0;
} 
