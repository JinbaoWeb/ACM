#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int M=5100005;
const int N=3000010;
const int SIGMA_SIZE = 26;
char str1[M],str2[M],str[M];
char wrd[1010];
void Change(char *s){
    int len=strlen(s);
    int j=0,q;
    for(int i=0;i<len;i++){
        if(str[i]==']')
            continue;
        if(s[i]=='['){
            i++;
            q=0;
            while(s[i]>='0' && s[i]<='9'){
                q=q*10+s[i]-'0';
                i++;
            }
            while(q--)
                str1[j++]=s[i];
        }else
            str1[j++]=s[i];
    }
    str1[j]='\0';
    for(int i=0;i<j;i++)
        str2[i]=str1[j-1-i];
    str2[j]='\0';
}
struct node{
    node* fail;
    node* next[SIGMA_SIZE];
    bool isword;
    int  id;
    void init(){
        id=0;
        isword=false;
        memset(next, 0, sizeof(next));
    }
};

class AC_Automation{
public:
    void init();
    void insert(char*,int);
    void getFail();
    int  find(char*);

private:
    node* new_node();
    int ID(char ch){return ch-'A';}

private:
    node Heap[N];
    node* root;
    int size;
};

node* AC_Automation::new_node(){
    Heap[size].init();
    return &Heap[size++];
}
void AC_Automation::init(){
    size=0;
    root=new_node();
}

void AC_Automation::insert(char* str,int id){
    node* p=root;
    for( ; *str; ++str){
        int ch=ID(*str);
        if(p->next[ch] == NULL)
            p->next[ch] = new_node();
        p = p->next[ch];
    }
    p->isword=true;
    p->id=id;
}
void AC_Automation::getFail(){
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
        node* tmp=Q.front(); Q.pop();
        for(int i=0; i<SIGMA_SIZE; ++i){
            node*& now = tmp->next[i];
            if(now != NULL){
                Q.push(now);
                if(tmp==root) now->fail=root;
                else{
                    node* p=tmp->fail;
                    while(p != NULL){
                        if(p->next[i] != NULL){
                            now->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p==NULL) now->fail=root;
                }
            }
            else{
                if(tmp==root) now = root;
                else now=tmp->fail->next[i];
            }
        }
    }
}
int AC_Automation::find(char* str){
    node* p=root;
    int cnt=0;
    for( ; *str; ++str){
        int ch=ID(*str);
        p = p->next[ch];
        if(p==NULL) p=root;
        node* tmp=p;
        while(tmp!=root && tmp->isword){
            ++cnt;
            tmp->isword=false;
            tmp = tmp->fail;
        }
    }
    return cnt;
}
AC_Automation ac;

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        ac.init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",wrd);
            ac.insert(wrd,i);
        }
        ac.getFail();
        scanf("%s",str);
        Change(str);
        printf("%d\n",ac.find(str1)+ac.find(str2));
    }
    return 0;
}