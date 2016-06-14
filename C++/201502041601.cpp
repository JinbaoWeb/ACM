//由前序和中序求后序
#include <iostream>
#include <string.h>
using namespace std;
typedef struct node{
	char data;
	node *left,*right;
}*tree;
char preorder[100],inorder[100];

/*		 由前序、中序构造树
*		 i: 子树的前序序列字符串的首字符在preorder[]中的下标
*        j: 子树的中序序列字符串的首字符在inorder[]中的下标
*      len: 子树的字符串序列的长度
*/
void CreatTree(tree &t,int i,int j,int len){
	if (len<=0)
		return;
	if (t==NULL){
		t=new node;
		t->left=t->right=NULL;
	}
	t->data=preorder[i];
	int m=strchr(inorder,preorder[i])-inorder;	//preorder[i]在inorder[]第几个字符
	CreatTree(t->left,i+1,j,m-j);
	CreatTree(t->right,i+(m-j)+1,m+1,len-1-(m-j));
}
/*后序遍历*/
void PostOrder(tree t){  
    if(t!=NULL){  
        PostOrder(t->left);  //访问左子结点           
        PostOrder(t->right);  //访问右子结点           
        cout<<(t->data);  //访问根节点
    }  
}  
int main(){
	while (cin>>preorder>>inorder){
		tree t=NULL;
		int len=strlen(preorder);
		CreatTree(t,0,0,len);
		PostOrder(t);
		cout<<endl;
	}

	return 0;
}