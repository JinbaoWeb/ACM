#include <bits/stdc++.h>
using namespace std;
int T;  
int tot;
map<string,string> father;
map<string,int> s;
map<string,int> opr;
void Class(){
    string ch,ch2;
    cin >> ch;
    int p=ch.find(':');
    if (p!=ch.npos){
        ch2=ch.substr(p+1);
        ch.erase(p);
        if (s[ch]==0 && s[ch2]==1){
            s[ch]=1;
            father[ch]=ch2;
            cout<<"class "<<ch<<':'<<ch2<<endl;
        }
        else{
            cout<<"oops!"<<endl;
        }
    }
    else{
        if (s[ch]){
            cout<<"oops!"<<endl;
            return;
        }
        else{
            s[ch]=1;
            cout<<"class "<<ch<<endl;
        }
    }
}
void Def(){
    string ch,ch2;
    cin>>ch;
    int p=ch.find('.');
    ch2=ch.substr(0,p);
    if (s[ch2]){
        if (opr[ch]){
            cout<<"redef "<<ch<<endl;
        }
        else{
            opr[ch]=1;
            cout<<"def "<<ch<<endl;
        }
    }
    else{
        cout<<"oops!"<<endl;
    }
}
void Undef(){
    string ch,ch2;
    cin>>ch;
    int p=ch.find('.');
    ch2=ch.substr(0,p);
    if (s[ch2]){
        if (opr[ch]){
            opr[ch]=0;
            cout<<"undef "<<ch<<endl;
        }
        else{
            cout<<"oops!"<<endl;
        }
    }
    else{
        cout<<"oops!"<<endl;
    }   
}
void Call(){
    string ch,ch2,op,now;
    cin>>ch;
    now=ch;
    int p=ch.find('.');
    op=ch.substr(p+1);
    ch=ch.substr(0,p);
    while ((!opr[now]) && (!ch.empty())){
        ch=father[ch];
        now=ch+'.'+op;
    }
    if (ch.empty()){
        cout<<"oops!"<<endl;
    }
    else{
        cout<<"invoke "<<now<<endl;
    }
}
int main(){
    scanf("%d",&T);
    while (T--){
        tot=0;
        string op;
        while (cin>>op){
            if (op=="begin"){
                father.clear();
                s.clear();
                opr.clear();
                continue;
            }
            if (op=="end")
                break;
            if (op=="class")
                Class();
            if (op=="def")
                Def();
            if (op=="undef")
                Undef();
            if (op=="call")
                Call();
        }
        cout<<endl;
    }
    
    return 0;
}