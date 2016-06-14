#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int M=5100005;
const int N=1000010;
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
//AC自动机
struct Trie{
    int count;
    Trie *next[26];
    Trie *fail;
    Trie(){
        count=0;
        fail=NULL;
        memset(next,NULL,sizeof(next));
    }
}*q[M];

Trie *NewNode(){
    Trie *tmp=new Trie;
    memset(tmp->next,NULL,sizeof(tmp->next));
    tmp->count=0;
    return tmp;
}

void Insert(char *str,Trie *root){
    Trie *loc=root;
    int i=0;
    while(str[i]!='\0'){
        int id=str[i]-'A';
        if(loc->next[id]==NULL)
            loc->next[id]=new Trie();
        loc=loc->next[id];
        i++;
    }
    loc->count++;
}

void AC(Trie *root){
    int head=0,tail=0;
    Trie *cur,*tmp;
    root->fail=NULL;
    q[tail++]=root;
    while(head!=tail){
        cur=q[head++];
        tmp=NULL;
        for(int i=0;i<26;i++){
            if(cur->next[i]==NULL)
                continue;
            if(cur==root)
                cur->next[i]->fail=root;
            else{
                tmp=cur->fail;
                while(tmp!=NULL){
                    if(tmp->next[i]!=NULL){
                        cur->next[i]->fail=tmp->next[i];
                        break;
                    }
                    tmp=tmp->fail;
                }
                if(tmp==NULL)
                    cur->next[i]->fail=root;
            }
            q[tail++]=cur->next[i];
        }
    }
}

int query(char *str,Trie *root){
    int ans=0;
    Trie *loc=root,*tmp;
    int i=0;
    while(str[i]!='\0'){
        int id=str[i]-'A';
        while(loc->next[id]==NULL && loc!=root)
            loc=loc->fail;
        loc=loc->next[id];
        loc=(loc==NULL)?root:loc;
        tmp=loc;
        while(tmp!=root){
            if(tmp->count>0){
                ans+=tmp->count;
                tmp->count=0;
            }else
                break;
            tmp=tmp->fail;
        }
        i++;
    }
    return ans;
}
Trie *root;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        root=new Trie();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",wrd);
            Insert(wrd,root);
        }
        AC(root);
        scanf("%s",str);
        Change(str);
        printf("%d\n",query(str1,root)+query(str2,root));
    }
    return 0;
}