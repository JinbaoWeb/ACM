#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int f(char s){
    if ('0'<=s&&s<='9')
        return s-'0';
    if ('a'<=s&&s<='z')
        return s-'a'+10;
}
int main(){
    int n,b;
    char s[205];
    int num[1000][205];
    int ans[205];
    while (cin>>n>>b){
    	memset(num,0,sizeof(num));
    	//memset(ans,0,sizeof(ans));
        int max_len=0;
        for (int i=0;i<n;i++){
            cin>>s;
            int len=strlen(s);
            if (len>max_len)
                max_len=len;
            for (int j=0;j<len;j++){
                num[i][j]=f(s[len-1-j]);
            }
        }
        for (int i=0;i<max_len;i++){
            ans[i]=0;
            for (int j=0;j<n;j++){
                ans[i]=(ans[i]+num[j][i])%b;
            }    
        }

        while (ans[max_len-1]==0&&max_len-1>=0)
            max_len--;
        if (max_len==0)
        	cout<<ans[max_len]<<endl;
        else{
        	while (max_len--)
            	cout<<ans[max_len];
        	cout<<endl;
        }
        
    }
    return 0;
}