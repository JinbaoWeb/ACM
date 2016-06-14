#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(int argc,char **argv){
	//ifstream cin("1318.txt");
	char dictionary[100][100],word[100];
	bool used[100];
	int k=0;
	while (cin>>dictionary[k++]){
		if (strcmp(dictionary[k-1],"XXXXXX")==0)
			break;
	}
	for (int i=0;i<k;i++)
		for (int j=i;j<k;j++){
			if (strcmp(dictionary[i],dictionary[j])>0){
				char s[100];
				strcpy(s,dictionary[i]);
				strcpy(dictionary[i],dictionary[j]);
				strcpy(dictionary[j],s);
			}
		}
	while (cin>>word){
		if (strcmp(word,"XXXXXX")==0)
			break;
		int len=strlen(word),flag=0;
		for (int i=0;i<k;i++){
			int len1=strlen(dictionary[i]);
			if (len!=len1)
				continue;
			memset(used,false,sizeof(used));
			int count=0;
			for (int j=0;j<len1;j++){	//控制字典上 
				for (int p=0;p<len;p++){	//控制word上的 
					if (dictionary[i][j]==word[p]&&used[p]==false){
						count++;
						used[p]=true;
						break;
					}						
				}
			}
			if (count==len){
				flag=1;
				cout<<dictionary[i]<<endl;
			}
				
		}
		if (flag==0)
			cout<<"NOT A VALID WORD"<<endl;
		cout<<"******\n";
	}
	return 0;
}
