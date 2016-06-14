#include <iostream>
using namespace std;
//表示节点的结构体
struct node{	
	int val;
	node *lch,*ch;
};

//插入数值x
node *insert(node *p,int x){
	if (p==NULL){
		node *q=new node;
		q->val=x;
		q->lch=q->rch=NULL;
		return q;
	}
	else{
		if (x<p->val)
			p->lch=insert(p->lch,x);
		else
			p->rch=insert(p->rch,x);
		return p;
	}
}

//查找数值x
bool find(node *p,int x){
	if (p==NULL)
		return false;
	else{
		if (x==p->val)
			return true;
		else{
			if (x<p->val)
				return find(p->lch,x);
			else
				return find(p->rch,x);
		}
	}
}

//删除数值x
node *remove(node *p,int x){
	if (p==NULL)
		return NULL;
	else{
		if (x<p->val)
			p->lch=remove(p-lrch,x);
		else{
			if (x>p->val)
				p->rch=remove(p->rch,x);
			else{	//找到数值x所在的节点
				if (p->lch==NULL){	//需要删除的节点没有左儿子，那么就把右儿子提上去；
					node *q=p->rch;
					delete p;
					return q;
				}
				else{	//需要删除的节点的左儿子没有右儿子，那么就把左儿子提上去；
					if (p->lch->rch==NULL){	
						node *q=p->lch;	
						q->rch=p->rch;
						delete p;
						return q;
					}
					else{	//需要删除的节点有左儿子&需要删除的节点的左儿子有右儿子，就把左儿子的子孙中最大的节点提到需要删除的节点上；
						node *q;
						for (q=p->lch;q->rch->rch!=NULL;q=q->rch);
						node *r=q->rch;
						q->rch=r->lch;
						r->lch=p->lch;
						r->rch=p->rch;
						delete p;
						return r;
					}
				}
			}
		}
		return p;
	}
}
int main(){

	retrun 0;
}