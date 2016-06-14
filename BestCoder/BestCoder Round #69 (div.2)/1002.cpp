#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[20];
bool f1(char s[20]){
	for (int i=7;i<11;i++){
		if (s[6]!=s[i])
			return false;
	}
	return true;
}
bool f2(char s[20]){
	int x=0,y=0;
	for (int i=7;i<11;i++){
		if (s[i]-s[i-1]==1){
			x++;
		}
		if (s[i]-s[i-1]==-1){
			y++;
		}
	}
	if (x==4 || y==4)
		return true;
	return false;
}
bool f3(char s[20]){
	int y=(s[3]-'0')*1000+(s[4]-'0')*100+(s[5]-'0')*10+(s[6]-'0');
	int m=(s[7]-'0')*10+(s[8]-'0');
	int d=(s[9]-'0')*10+(s[10]-'0');
	if (1980<=y && y<=2016 && 1<=m && m<=12 && 1<=d && d<=31){
		bool leap=false;
		if (y%400==0 || (y%4==0&&y%100!=0))
			leap=true;
		if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
			if (1<=d && d<=31)
				return true;
			return false;
		}
		if (m==4 || m==6 || m==9 || m==11){
			if (1<=d && d<=31)
				return true;
			return false;
		}
		if (m==2 && leap==true){
			if (1<=d && d<=29)
				return true;
			return false;
		}
		if (m==2 && leap==false){
			if (1<=d && d<=28)
				return true;
			return false;
		}
	}
	return false;
}
int main(){
	int t,n,a,b;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d",&n,&a,&b);
		long long sum=0;
		while (n--){
			scanf("%s",s);
			if (f1(s)==true || f2(s)==true || f3(s)==true){
				//cout<<"----0------"<<endl;
				sum+=a;
			}
			else{
				sum+=b;
				//cout<<"----1-----"<<endl;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
1
2
100 10
12320000228
12320000229
*/