#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
struct change{
	char a[20],b[20];
}word[3000+2];

int main(){
	char a[20],b[20];
	int n,m;
	while (cin>>n>>m){
		for (int i=0;i<m;i++){
			cin>>a>>b;
			int len_a=strlen(a),len_b=strlen(b);
			if (len_a<=len_b){
				strcpy(word[i].a,a);
				strcpy(word[i].b,b);
			}
			else{
				strcpy(word[i].a,b);
				strcpy(word[i].b,a);
			}
		}
		for (int i=0;i<n;i++){
			cin>>a;
			for (int j=0;j<m;j++){
				if (strcmp(word[j].a,a)==0||strcmp(word[j].b,a)==0){
					if (i==n-1)
						cout<<word[j].a<<endl;
					else
						cout<<word[j].a<<" ";
					break;
				}
			}
		}
	}
	return 0;
}