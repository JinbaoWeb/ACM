#include <iostream>
#include <string.h>
using namespace std;
typedef struct node{
	char data;
	node *left,*right;
}*tree;
char inorder[100],post[100];
/*		由中序和后序构造树
*		i: 子树的后序序列字符串的首字符在post[]中的下标
*		j: 子树的中序序列字符串的首字符在inorder[]中的下标
*	  len: 子树的字符串序列的长度
*/
void CreatTree(tree &t,int i,int j,int len){
	if (len<=0)
		return;
	if (t==NULL){
		t=new node;
		t->left=t->right=NULL;
	}
	t->data=post[i];
	int m=strchr(inorder,post[i])-inorder;	//post[i]在inorder[]第几个字符
	CreatTree(t->left,i-1-(len-1-(m-j)),j,m-j);	//m-j左子树的长度,len-1-(m-j)右子树的长度
	CreatTree(t->right,i-1,m+1,len-1-(m-j));
}
/*前序遍历*/
void PreTravelTree(tree t){
	if (t){
		cout<<t->data;
		PreTravelTree(t->left);
		PreTravelTree(t->right);
	}
}
int main(){
	while (cin>>inorder>>post){
		tree t=NULL;
		int len=strlen(inorder);
		CreatTree(t,len-1,0,len);
		PreTravelTree(t);
		cout<<endl;
	}
	return 0;
}