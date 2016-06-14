#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1000000 + 5;
int p[MAXN];
char s[MAXN];
char str[2*MAXN+3];
void init(){
    int len=strlen(s);
    str[0]='$';
    for (int i=1;i<2*len+1;i++){
        if (i&1==0)
            str[i]='#';
        else
            str[i]=s[i/2-1];
    }
    str[2*len+1]=0;
}
int solve(){
    int mx=0,id=0;
    memset(p, 0, sizeof(p));
    for (int i = 1; s[i] != '\0'; i++) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (str[i + p[i]] == str[i - p[i]]) 
            p[i]++;
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
    }
}
}
int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>s;
        init();
        cout<<solve()<<endl;
    }
    return 0;
}