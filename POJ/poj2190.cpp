#include <iostream>
using namespace std;
int main(){
	char a[11];
	int k,sum;
	while (cin>>a){
		int sum=0,index=0;
		for (int i=0;i<10;i++){
			if ('0'<=a[i]&&a[i]<='9')
				sum+=(a[i]-'0')*(10-i);
			if (a[i]=='X')
				sum+=(10-i)*10;
			if (a[i]=='?')
				index=i;
		}
		int flag=0;
		for (int k=0;k<10;k++){
			if ((sum+k*(10-index))%11==0){
				flag=1;
				cout<<k<<endl;
				break;
			}
		}
		if (flag==0){
			if (index==9&&(sum+10*(10-index))%11==0)
				cout<<'X'<<endl;
			else
				cout<<-1<<endl;
		}
		
			
	}
	return 0;
}
