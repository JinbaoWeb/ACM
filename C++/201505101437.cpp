/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-10 14:37
 * Filename :        201505101437.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int t,n,m;
struct P{
	char s[11];
	int num;
}p[505];
char str[11];
int main(){
	scanf("%d",&t);
	for (int cas=1;cas<=t;cas++){
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++){
			scanf("%s",&p[i].s);
			p[i].num=0;
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++){
				scanf("%s",&str);
				for (int k=0;k<m;k++){
					if (strcmp(p[k].s,str)==0){
						p[k].num+=(m-j);
						break;
					}
				}
			}
		int max=0;
		char temp[11];
		for(int i=0;i<m;i++){
			if (p[i].num>max){
				max=p[i].num;
				strcpy(temp,p[i].s);
			}
		}
		cout<<"Case #"<<cas<<": "<<temp<<endl;
	}

	return 0;
}
