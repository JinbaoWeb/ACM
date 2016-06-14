#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int n,x,y;
	char map[11][11];
	bool used[11][11];
	cin>>n;
	while (n--){
		cin>>x>>y;
		for (int i=0;i<11;i++){
			for (int j=0;j<11;j++){
				used[i][j]=false;
			}
		}
		for (int i=0;i<x;i++)
			cin>>map[i];
		int flag=0;
		for (int i=0;i<x;i++){
			for (int j=0;j<y;j++){
				if (map[i][j]!='.'&&used[i][j]==false){
					used[i][j]=true;
					flag++;
					if (flag>1){
						cout<<"INCORRECT"<<endl;
						break;
					}
						
					if (map[i][j]=='-'){
						for (int k=j+1;k<y;k++){
							if (map[i][k]=='-'&&used[i][k]==false){
							
								used[i][k]=true;
							}
								
							else
								break;
						}
					}
					if (map[i][j]=='|'){
						for (int k=i+1;k<x;k++){
							if (map[k][j]=='|'&&used[k][j]==false)
									used[k][j]=true;
							else
								break;
							
						}
					}
					if (map[i][j]=='/'){
						for (int k=1;i+k<x&&j-k>=0;k++){
							if (map[i+k][j-k]=='/'&&used[i=k][j-k]==false)
								used[i+k][j-k]=true;
							else
								break;
						}
					}
					if (map[i][j]=='\\'){
						for (int k=1;i+k<=x&&j+k<=y;k++){
							if (map[i+k][j+k]=='\\'&&used[i+k][j+k]==false)
								used[i+k][j+k]=true;
							else
								break;
						}
					}
				}
			}
			if (flag>1)
				break;
		}
		if (flag==1)
			cout<<"CORRECT"<<endl;
		if (flag==0)
			cout<<"INCORRECT"<<endl;
	}
	return 0;
} 
