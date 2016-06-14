#include <iostream>
#include <cstdio>
#include <string.h>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int man[102],feman[102];
int n,m,a,b,index;
bool check(){
	
    for (int i=0;i<n;i++){
        if (man[i]==0)
            return false;
    }
    
    for (int i=0;i<m;i++){
        if (feman[i]==0)
            return false;
    }
    return true;
}
int main(){
    while (cin>>n>>m){
        memset(man,0,sizeof(man));
        memset(feman,0,sizeof(feman));
        cin>>a;
        for (int i=0;i<a;i++){
            cin>>index;
            man[index]=1;
        }
        cin>>b;
        for (int i=0;i<b;i++){
            cin>>index;
            feman[index]=1;
        }
        int s=a+b;
    }
    return 0;
}