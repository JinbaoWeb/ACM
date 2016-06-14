#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int n;
	char s[500],map[500][500];
	while (cin>>n&&n){
		cin>>s;
		int len=strlen(s),k=0,flag=0;
		while (k<len){
			for (int i=0;i<n;i++)
				map[flag][i]=s[k++];
			flag++;
			if (k==len)
				break;
			for (int j=n-1;j>=0;j--)
				map[flag][j]=s[k++];
			flag++;
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<flag;j++){
				cout<<map[j][i];
			}
		}
		cout<<endl;
			
	}
	return 0;
}