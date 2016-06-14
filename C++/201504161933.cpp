#include <iostream>
#include <string.h>
using namespace std;
#define inf 0xffffff
int dp[105][105];
int pos[105][105];
char s[105];
void show(int i,int j){
	if (i>j)	
		return;
	if (i==j){
		if(s[i]=='('||s[i]==')') 
			cout<<"()";
  		else	
  			cout<<"[]";
  	}
  	else{
  		if (pos[i][j]==-1){
  			cout<<s[i];
  			show(i+1,j-1);
  			cout<<s[j];
  		}
  		else{
  			show(i,pos[i][j]);
  			show(pos[i][j]+1,j);
  		}
  	}
}

int main(){		
	while (cin>>s){ if (strcmp(s,"end")==0) break;
	int n=strlen(s);
	for (int i=0;i<n;i++){
		dp[i][i-1]=0;
		dp[i][i]=1;
	}
	for (int k=1;k<n;k++){	//表示i跟j之间的距离
		for (int i=0;i<n-k;i++){
			int j=i+k;
			dp[i][j]=inf;
			if ((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']')){
				pos[i][j]=-1;
				dp[i][j]=dp[i+1][j-1];
			}
			for (int p=i;p<j;p++){
				if (dp[i][j]>dp[i][p]+dp[p+1][j]){
					pos[i][j]=p;
					dp[i][j]=dp[i][p]+dp[p+1][j];
				}
			}
		}
	}
	show(0,n-1);
	cout<<endl;
}
	return 0;
}