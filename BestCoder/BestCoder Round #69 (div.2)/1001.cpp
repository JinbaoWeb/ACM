#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int a,b,c,t;
	cin>>t;
	while (t--){
		cin>>a>>b>>c;
		if (c%2!=0){
			cout<<"Impossible"<<endl;
			continue;
		}
		int k=c/2,flag=0;
		int ansi=-1,ansj=-1;
		for (int i=0;;i++){
			if (i*a>k)
				break;
			for (int j=0;;j++){
				if (i*a+j*b==k){
					flag=1;
					if (ansi==-1 && ansj==-1)
						ansi=i*2,ansj=j*2;
					else{
						if (ansi+ansj>i*2+j*2){
							ansi=i*2,ansj=j*2;
						}
					}
				}
				if (i*a+j*b>k)
					break;
			}
		}
		if (flag==0)
			cout<<"Impossible"<<endl;
		else
			cout<<ansi<<" "<<ansj<<endl;
	}
	return 0;
}
