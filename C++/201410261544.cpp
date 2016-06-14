#include <iostream>
#include <string.h>
using namespace std;
bool istrue(int a){
	
	while (a>9){
		int b=a;
		a=0;
		while (b){
			a=a+b%10;
			b=b/10;
		}
	}
	if (a==9)
		return true;
	return false;
}
int main(){
	char s[10005];
	int t;
	cin>>t;
	while (t--){
		cin>>s;
		int count=0;
		int len=strlen(s);
		for (int i=0;i<len;i++){
			int sum=0;
			for (int k=1;k<=4;k++){
				if (i+k-1>=len)
					continue;
				sum=0;
				for (int j=i;j<i+k;j++)
					sum+=s[j]-'0';
				if (istrue(sum)==true){
					cout<<i<<" "<<k<<endl;
					count++;
				}
					
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
