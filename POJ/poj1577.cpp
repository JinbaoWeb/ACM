#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1005
struct node{
	char val;
	node *lch,*rch;
};
char s[MAX];
node *insert(node *p,char val){
	if (p==NULL){
		node *q=new node;
		q->val=val;
		q->lch=q->rch=NULL;
		return q;
	}
	else{
		if (val<p->val)
			p->lch=insert(p->lch,val);
		else
			p->rch=insert(p->rch,val);
		return p;
	}
}
void show(node *p){
	if (p==NULL)
		return;
	cout<<p->val;
	if (p->lch!=NULL)
		show(p->lch);
	if (p->rch!=NULL)
		show(p->rch);
}
int main(){
	while (cin>>s){
		int len=strlen(s);
		char str;
		while (1){
			cin>>str;
			if (str=='*'||str=='$')
				break;
			s[len++]=str;
		}
		node *p=NULL;
		while (len-->0){
			p=insert(p,s[len]);
		}
		show(p);
		cout<<endl;
	}
	return 0;
}