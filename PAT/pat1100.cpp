#include <iostream>
#include <string.h>
using namespace std;
int main(){
	char s[4][100];
	char s1[7][10]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int len[4];
	while (cin>>s[0]){
		len[0]=strlen(s[0]);
		for (int i=1;i<4;i++){
			cin>>s[i];
			len[i]=strlen(s[i]);
		}
		int len1=len[0]<len[1]?len[0]:len[1],len2=len[2]<len[2]?len[2]:len[3],flag=0;
		for (int i=0;i<len1;i++){
			if (flag==0&&s[0][i]==s[1][i]&&((s[0][i]>='A'&&s[0][i]<='Z')||(s[0][i]>='a'&&s[0][i]<='z'))){
				if (s[0][i]>='A'&&s[0][i]<='Z')
					cout<<s1[s[0][i]-'A'];
				else
					cout<<s1[s[0][i]-'a'];
				cout<<" ";
				flag++;
				continue;
			}
			if (flag==1&&s[0][i]==s[1][i]&&((s[0][i]>='A'&&s[0][i]<='N')||(s[0][i]>='0'&&s[0][i]<='9'))){
				if (s[0][i]>='A'&&s[0][i]<='N'){
					int k=s[0][i]-'A'+10;
					cout<<k/10<<k%10<<":";
				}
				else
					cout<<s[0][i]-'0'<<":";
				break;
			}
		}	
		for (int i=0;i<len2;i++){
			if (s[2][i]==s[3][i]&&((s[2][i]>='A'&&s[3][i]<='Z')||(s[2][i]>='a'&&s[3][i]<='z'))){
				if(0<=i&&i<=9)
					cout<<0;
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
	
}
