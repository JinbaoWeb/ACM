#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 1000005
using namespace std;
struct SBT{
	int left,right,size,key;	//左子树指针，右子树指针，大小，键值
	void Init(){
		left=right=key=0;
		size=1;
	}
}T[N];
int root,tot; //根的位置以及节点个数
void Left_rot(int &x){  //左旋转处理
	int k=T[x].right;
	T[x].right=T[k].left;
	T[k].left=x;
	T[k].size=T[x].size;
	T[x].size=T[T[x].left].size+T[T[x].right].size+1;
	x=k;
}
void Right_rot(int &x){	//右旋转处理
	int k=T[x].left;
	T[x].left=T[k].right;
	T[k].right=x;
	T[k].size=T[x].size;
	T[x].size=T[T[x].left].size+T[T[x].right].size+1;
	x=k;
}
void Maintain(int &r,bool flag){	//调整处理
	if(flag){  //更新右子树
		if(T[T[T[r].right].right].size>T[T[r].left].size)
			Left_rot(r);
		else if(T[T[T[r].right].left].size>T[T[r].left].size){
			Right_rot(T[r].right);
			Left_rot(r);
		}
		else
			return;
	} 
	else{   //更新在左子树
		if(T[T[T[r].left].left].size>T[T[r].right].size)
			Right_rot(r);
		else if(T[T[T[r].left].right].size>T[T[r].right].size){
			Left_rot(T[r].left);
			Right_rot(r);
		}
		else 
			return;
	}
	//更新子树，然后再更新根，直到平衡为止
	Maintain(T[r].left,false);
	Maintain(T[r].right,true);
	Maintain(r,false);
	Maintain(r,true);
}
void Insert(int &r,int k){	//插入新节点
	if(r==0){
		r=++tot;
		T[r].Init();
		T[r].key=k;
	}
	else{
		T[r].size++;
		if(k<T[r].key)
			Insert(T[r].left,k);
		else
			Insert(T[r].right,k);
		//插入后要调整，保证平衡
		Maintain(r,k>=T[r].key);
	}
}
int Remove(int &r,int k){	//删除结点，利用的是前驱替换
	int d_key;
	if(!r)
		return 0;
	T[r].size--;
	//前者说明就是要删的节点，后两者说明不存在此节点
	if(T[r].key==k||(T[r].left==0&&k<T[r].key)||(T[r].right==0&&k>T[r].key)){
		d_key=T[r].key;
		if(T[r].left&&T[r].right)
			T[r].key=Remove(T[r].left,k+1);
		else
			r=T[r].left+T[r].right;
	}
	else Remove(k<T[r].key?T[r].left:T[r].right,k);
}
void Delete(int &r,int delay,int min_val){  
    if(!r) return;  
    if(T[r].key+delay<min_val) {  
        r=T[r].right;  
        Delete(r,delay,min_val);  
    }  
    else{  
        Delete(T[r].left,delay,min_val);  
        T[r].size=T[T[r].right].size+T[T[r].left].size+1;  
    }  
}  
int Get_Max(int r){	//取得最大值，即一直遍历到最右的结点
	while(T[r].right)
		r=T[r].right;
	return r;
}
int Get_Min(int r){	//取得最小值，即一直遍历到最左的结点
	while(T[r].left)
		r=T[r].left;
	return r;
}
int Get_Pre(int &r,int y,int k){	//获得前驱
	if(r==0) return y;
	if(k>T[r].key)
		Get_Pre(T[r].right,r,k);
	else
		Get_Pre(T[r].left,y,k);
}
int Get_Next(int &r,int y,int k){	//获得前驱
	if(r==0) return y;
	if(k<T[r].key)
		Get_Next(T[r].left,r,k);
	else
		Get_Next(T[r].right,y,k);
}  
int Get_Min_Kth(int &r,int k){  	//取得第K小的数，注：暂不能解决有重复数的
    int t=T[T[r].left].size+1;  
    if(t==k) return T[r].key;  
    if(t<k)  return Get_Min_Kth(T[r].right,k-r);  
    else return Get_Min_Kth(T[r].left,k);  
}    
int Get_Max_Kth(int &r,int k){  	//取得第K大的数
    int t=T[T[r].right].size+1;  
    if(t==k) return T[r].key;  
    if(t<k) return Get_Max_Kth(T[r].left,k-t);  
    else return Get_Max_Kth(T[r].right,k);  
}  
int Get_Rank(int &r,int k){			//获得结点的名次
	if(k<T[r].key) 
		return Get_Rank(T[r].left,k);
	else if(k>T[r].key)
		return Get_Rank(T[r].right,k)+T[T[r].left].size+1;
	else
		return T[T[r].left].size+1;
}
void Inorder(int &r){	//排序
	if(r==0) return;
	Inorder(T[r].left);
	printf("%d\n",T[r].key);
	Inorder(T[r].right);
}
int main(){
	int n,Min,v,flag;
	char str[2];
	while (~scanf("%d%d",&n,&Min)){
		scanf("%s%d",str,&v);
		root=tot=0;
		flag=0;
		if (str[0]=='I'){
			if (v<Min)
				continue;
			Insert(root,v-flag);
		}
		if (str[0]=='A'){
			flag+=v;
		}
		if (str[0]=='S'){
			flag-=v;
			Delete(root,flag,Min);
		}
		if (str[0]=='F'){
			printf("%d\n",T[root].size );
			if (T[root].size<v){
				printf("-1\n");
				continue;
			}
			int ans=Get_Max_Kth(root,v)+flag;
			printf("%d\n",ans );
		}
	}
	return 0;
}