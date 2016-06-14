#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
struct Node{
	char s[5];
	double num;
}map[20];
int main(){
	strcpy(map[0].s,"A"); map[0].num=4.0;
	strcpy(map[1].s,"A-");map[1].num=3.7;
	strcpy(map[2].s,"B+");map[2].num=3.3;
	strcpy(map[3].s,"B"); map[3].num=3.0;
	strcpy(map[4].s,"B-");map[4].num=2.7;
	strcpy(map[5].s,"C+");map[5].num=2.3;
	strcpy(map[6].s,"C"); map[6].num=2.0;
	strcpy(map[7].s,"C-");map[7].num=1.7;
	strcpy(map[8].s,"D"); map[8].num=1.3;
	strcpy(map[9].s,"D-");map[9].num=1.0;
	strcpy(map[10].s,"F"); map[10].num=0;
	int n,k;
	char str[5];
	while (~scanf("%d",&n)){
		int sum=0;
		double sorce=0;
		while (n--){
			scanf("%d%s",&k,str);
			int flag=0;
			for (int i=0;i<11;i++){
				if (strcmp(str,map[i].s)==0){
					//cout<<"-------"<<endl;
					flag=1;
					sorce+=k*map[i].num;
					break;
				}
			}
			if (flag==1)
				sum+=k;
		}
		//cout<<sorce<<" "<<sum<<endl;
		if (sum==0)
			cout<<"0.00"<<endl;
		else
			printf("%.2f\n",sorce/sum);
	}
	return 0;
}