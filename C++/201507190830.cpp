#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
struct Node{
	char name[33];
	int value;
	char position[100];
}G[30],D[30],M[30],S[30];
struct Node2{
	char name1[33],name2[33];
	int add;
}A[1000];
int count_g=0,count_d=0,count_s=0,count_m=0;
void resolve(char name[],int value,char position[]){
	if (strcmp(position,"goalkeeper")==0){
		count_g++;
		G[count_g].value=value;
		strcpy(G[count_g].name,name);
		strcpy(G[count_g].position,position);
	}	
	if (strcmp(position,"defender")==0){
		count_d++;
		D[count_d].value=value;
		strcpy(G[count_d].name,name);
		strcpy(G[count_d].position,position);
	}
	if (strcmp(position,"midfielder")==0){
		count_m++;
		M[count_m].value=value;
		strcpy(M[count_m].name,name);
		strcpy(M[count_m].position,position);
	}
	if (strcmp(position,"striker")==0){
		count_s++;
		S[count_s].value=value;
		strcpy(S[count_s].name,name);
		strcpy(S[count_s].position,position);
	}
}
int main(){
	while (~scanf("%s%d%s",name,&value,position)){
		count_g=0,count_d=0,count_s=0,count_m=0;
		char name,position;
		int value;
		resolve(name,value,position);
		for (int i=1;i<23;i++){
			scanf("%s%d%s",name,&value,position);
			resolve(name,value,position);
		}
		int m;
		cin>>m;
		for (int i=0;i<m;i++)
			cin>>A[i].name1>>A[i].name2>>A[i].add;
		if (count_m>=4 && count_d>=4 && count_s>=2 && count_g>=1){
			for (int m1=0;m1<count_m;m1++){

			}
		}
		else{
			cout<<"impossible"<<endl;
		}

	}

	return 0;
}