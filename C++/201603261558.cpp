#include <bits/stdc++.h>
using namespace std;
char str1[30],str2[30];
char Class[100][30];
int class_num=0;
char Method[100][30];
int method_num=0;
struct Node{
	char Cl[30];
	char subCl[30];
}ClandSubCl[100];
int clsub_num=0;
struct Node2{
	char Cl[30];
	char Me[30];
}ClMe[100];
int clme_num=0;
int f1(char str2[],char temp1[],char temp2[],char s){
	int i=-1;
	int len=strlen(str2);
	for (int j=0;j<len;j++){
		if (str2[j]==s){
			i=j;
			break;
		}
	}
	for (int j=0;j<i;j++){
		temp1[j]=str2[j];
	}
	temp1[i]=0;
	if (i){
		for (int j=i+1;j<len;j++)
			temp2[j-i-1]=str2[j];
		temp2[len-i-1]=0;
	}
	return (i==-1?0:1);
}
int main(){
	int t;
	cin>>t;
	char temp1[20],temp2[20];
	while (t--){
		class_num=0;
		method_num=0;
		clsub_num=0;
		clme_num=0;
		while (cin>>str1){
			if (strcmp(str1,"begin")==0) continue;
			if (strcmp(str1,"end")==0) break;
			cin>>str2;
			if (strcmp(str1,"class")==0){
				int flag=f1(str2,temp1,temp2,':');
				if (flag==0){
					cout<<str1<<" "<<str2<<endl;
					strcpy(Class[class_num++],str2);
				}
				else{
					int flagflag=0,flagflag2=0;
					for (int i=0;i<class_num;i++){
						if (strcmp(Class[i],temp1)==0){
							flagflag=1;
						}
						if (strcmp(Class[i],temp2)==0){
							flagflag2=1;
						}
					}
					if (flagflag==1 || flagflag2==0)
						cout<<"oops!"<<endl;
					else{
						cout<<str1<<" "<<str2<<endl;
						strcpy(Class[class_num++],temp1);
						strcpy(ClandSubCl[clsub_num].Cl,temp1);
						strcpy(ClandSubCl[clsub_num++].subCl,temp2);
					}
				}
			}
			if (strcmp(str1,"def")==0){
				int flag=f1(str2,temp1,temp2,'.');
				int flagflag=0,flagflag2=0;
				for (int i=0;i<class_num;i++){
					if (strcmp(Class[i],temp1)==0){
						flagflag=1;
						break;
					}
				}
				for (int i=0;i<method_num;i++){
					if (strcmp(Method[i],temp2)==0){
						flagflag2=1;
						break;
					}
				}
				if (flagflag==0){
					cout<<"oops!"<<endl;
				}
				else{
					int flag3=0;
					for (int i=0;i<clme_num;i++){
						if (strcmp(ClMe[i].Cl,temp1)==0 && strcmp(ClMe[i].Me,temp2)==0){
							cout<<"re"<<str1<<" "<<str2<<endl;
							flag3=1;
							break;
						}
					}
					if (flag3==0){
						cout<<str1<<" "<<str2<<endl;
						strcpy(Method[method_num++],temp2);
						strcpy(ClMe[clme_num].Cl,temp1);
						strcpy(ClMe[clme_num++].Me,temp2);
					}
				}
			}
			if (strcmp(str1,"undef")==0){
				int flag=f1(str2,temp1,temp2,'.');
				int flagflag=0,flagflag2=0;
				for (int i=0;i<class_num;i++){
					if (strcmp(Class[i],temp1)==0){
						flagflag=1;
						break;
					}
				}
				for (int i=0;i<method_num;i++){
					if (strcmp(Method[i],temp2)==0){
						flagflag2=1;
						break;
					}
				}
				if (flagflag==0 && flagflag2==0){
					cout<<"oops!"<<endl;
				}
				else{
					cout<<str1<<" "<<str2<<endl;
					strcpy(Class[class_num++],temp1);
				}
			}
			if (strcmp(str1,"call")==0){
				int flag=f1(str2,temp1,temp2,'.');
				int flagflag=0,flagflag2=0;
				for (int i=0;i<class_num;i++){
					if (strcmp(Class[i],temp1)==0){
						flagflag=1;
						break;
					}
				}
				for (int i=0;i<method_num;i++){
					if (strcmp(Method[i],temp2)==0){
						flagflag2=1;
						break;
					}
				}
				//cout<<flagflag<<" "<<flagflag2<<endl;
				if (flagflag==1 && flagflag2==1){
					for (int i=0;i<clme_num;i++){
						if (strcmp(ClMe[i].Cl,temp1)==0 && strcmp(ClMe[i].Me,temp2)==0){
							cout<<"invoke "<<ClMe[i].Cl<<"."<<ClMe[i].Me<<endl;
							break;
						}
					}
					
					for (int i=0;i<clsub_num;i++){
						//cout<<"-----"<<ClandSubCl[i].Cl<<" "<<ClandSubCl[i].subCl<<endl;
						if (strcmp(ClandSubCl[i].Cl,temp1)==0){
							strcpy(temp1,ClandSubCl[i].subCl);
							//cout<<temp1<<endl;
							for (int j=0;j<clme_num;j++){
								if (strcmp(ClMe[j].Cl,temp1)==0 && strcmp(ClMe[j].Me,temp2)==0){
									cout<<"invoke "<<ClMe[j].Cl<<"."<<ClMe[j].Me<<endl;
									break;
								}
							}
							i=-1;
						}
					}
				}
				else{
					cout<<"oops!"<<endl;
				}
			}

		}
		cout<<endl;
	}
	return 0;
}