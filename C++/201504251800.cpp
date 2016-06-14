#include <iostream>
using namespace std;
int main(){
	for (int j=1;j<10;j++){
		int a[100];
		int k=0;
		while (j){
			a[k++]=j%2;
			j/=2;
		}
		int flag=0,flagflag=1;
		for (int i=0;i<k;i++){
			if (a[i]==1 && flag==0)
				flag=1;
			if ((a[i]==1 && flag==1)||(a[i]==0 && flag==0)){
				flagflag=1;
				break;
			}
		}
		if (flagflag=0)
			cout<<j<<endl;
	}

	return 0;
}
