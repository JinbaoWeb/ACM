#include <bits/stdc++.h>
using namespace std;
char str[100000+10];
char tmp[100000+10];
int Sum(){
	int ans=0;
	int len=strlen(str);
	for (int i=0;i<len;i++){
		ans+=str[i]-'0';
	}
	return ans;
}
void addone(){
	int len=strlen(str);
	int add=1;
	int flag=0;
	for (int i=len-1;i>=0;i--){
		if (str[i]=='9'){
			str[i]='0';
		}
		else{
			str[i]+=1;
			add=0;
			flag=1;
			break;
		}
	}
	if (flag==0){
		str[0]='1';
		for (int i=1;i<=len;i++){
			str[i]='0';
		}
		str[len+1]=0;
	}
}
int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>str;
		while (1){
			addone();
			//cout<<str<<endl;
			if (Sum()%10==0){
				cout<<str<<endl;
				break;
			}
		}
	}

	return 0;
}