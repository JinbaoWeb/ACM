#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct word{
	char old[22];
	char news[22];
}w[1002];
bool cmp(word a,word b){
	if (strcmp(a.old,b.old)>0)
		return false;
	else{
		if (strcmp(a.old,b.old)==0){
			if (strcmp(a.news,b.news)>0)
				return false;
			return true;
		}
		return true;
	}
}
int main(){
	int nn,k=0;
	char o[22],n[22];
	bool used[1002];
	cin>>nn;
	for (int i=0;i<nn;i++){
		cin>>o>>n;
		int flag=0;
		for (int j=0;j<k;j++){
			if (strcmp(w[j].news,o)==0){
				strcpy(w[j].news,n);
				flag=1;
				break;
			}
		}
		if (flag==0){
			strcpy(w[k].old,o);
			strcpy(w[k].news,n);
			k++;
		}
	}
	//cout<<"-------------------------------"<<endl;
	sort(w,w+k,cmp);
	for (int i=0;i<k;i++){
		cout<<w[i].old<<" "<<w[i].news<<endl;
	}
	return 0;
}