#include <iostream>
#include <string.h>
using namespace std;
int F[1005];
void init(){
	for (int i=1;i<=1000;i++){
		int num=0;
		for (int j=1;j<=i;j++){
			if (i%j==0)
				num++;
		}
		F[i]=num;
	}
}
int main(){
	int x,t;
	init();
	cin>>t;
	while (cin>>x){
		int flag=0;
		for (int i=1;i<=1000;i++){
			if (F[i]==x){
				cout<<i<<endl;
				flag=1;
				break;
			}
		}
		if (flag==0)
			cout<<-1<<endl;
	}

	return 0;
}