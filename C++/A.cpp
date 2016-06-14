#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[1005][100][100];
char str[1000];
int ans[1000];
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		cin.getline(str,1000);
		memset(s,0,sizeof(s));
		memset(ans,0,sizeof(ans));
		int k=0,num=0;
		while (1){
			cin.getline(str,1000);
			if (strcmp(str,"@")==0){
				break;
			}
			int len=strlen(str);
			num=0;
			int left=0;
			int i=0;
			int flag=0;
			while (i<len){
				for (;i<len;i++)
					if (str[i]!=' ')
						break;
				//cout<<i<<endl;
				for (;i<len;i++){
					if (str[i]==' ')
						break;
					flag=1;
					s[k][num][left++]=str[i];
				}
				s[k][num][left]=0;
				left=0;
				//cout<<s[k][num]<<endl;
				num++;
			}
			if (flag!=0)
				k++;
			//cin.getline(str,200);
		}
		/*
		//test
		for (int i=0;i<k;i++){
			for (int j=0;j<20;j++){
				cout<<s[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		for (int j=0;j<1000;j++){
			int Max=0;
			for (int i=0;i<k;i++){
				int len=strlen(s[i][j]);
				if (len>Max)
					Max=len;
			}
			ans[j+1]=Max;
		}
		for (int i=1;i<1000;i++)
			ans[i]++;
		/*
		//test
		for (int i=0;i<20;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		*/
		for (int i=0;i<k;i++){
			for (int j=0;j<1000;j++){
				int len=strlen(s[i][j]);
				cout<<s[i][j];
				int len2=strlen(s[i][j+1]);
				if (len2==0)
					break;
				for (int ii=0;ii<ans[j+1]-len;ii++)
					cout<<" ";

			}
			cout<<endl;
		}
		
	}

	return 0;
}