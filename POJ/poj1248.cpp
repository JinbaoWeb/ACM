#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main(){
	int n;
	char s[100];
	while (cin>>n){
		cin>>s;
		if (n==0&&strcmp(s,"END")==0)
			break;
		int len=strlen(s),i,j,k,p,q,flag=0;
		for (i=0;i<len;i++){

			for (j=0;j<len;j++){
				
				for (k=0;k<len;k++){
					
					for (p=0;p<len;p++){
						
						for (q=0;q<len;q++){
							
							if (s[i]-'A'+1-pow(s[j]-'A'+1,2)+pow(s[k]-'A'+1,3)-pow(s[p]-'A'+1,4)+pow(s[q]-'A'+1,5)==n){
								cout<<s[i]<<s[j]<<s[k]<<s[p]<<s[q]<<endl;
								flag=1;
								//goto C;
							}
						}
					}
				}
			}
		}
		//C:
		if (flag==0)
			cout<<"no solution"<<endl;
	}
	return 0;
}