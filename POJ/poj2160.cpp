#include <iostream>
#include <string.h>
using namespace std;
struct rectangle{
	int w,l;
}r[6];

int main(){
	int l,w;
	for (int i=0;i<6;i++){
		cin>l>>w;
		if (l<w){
			int temp=l;
			l=w;
			w=temp;
		}
		int flag=0;
		for (int j=0;j<k;j++){
			if (r[j].l==l&&r[j].w==w){
				flag=1;
				break;
			}
		}
		if (flag==0){
			r[k].l=l;
			r[k].w=w;
			k++;
		}
	}
	if (k==3){
		int a=r[0].l,b=r[0].w,c=0;
		

	}
	return 0;
}