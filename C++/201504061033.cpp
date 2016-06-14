#include <iostream>
using namespace std;

#define TRUE   1  
#define FALSE   0  
#define OK    1  
#define ERROR   0  
#define INFEASIBLE -1  
#define OVERFLOW -2  
  
#define LT(a,b)   ((a)<(b))  
#define N = 100      

typedef int Status;  
typedef int ElemType; 

/****************线性表的动态分配顺序存储结构*********************/
#define LIST_INIT_SIZE 100 //线性表初始空间分配量  
#define LISTINCREMENT   10 //线性表空间分配的增量  
typedef struct LNode{  
    ElemType  *elem;        //存储空间的基地址  
    int      lenght;        //当前的长度  
    int      listsize;      //当前分配的存储容量  
}SqList;  

/**********************构造空线性表*******************************/
Status initList(SqList &L, int lenght){  
    if (lenght == 0) lenght = LIST_INIT_SIZE; 
    L.elem = new ElemType(lenght);
    if(!L.elem) exit(OVERFLOW);  //分配存储空间失败  
    L.lenght = 0;                //初始空表长度为0  
    L.listsize = lenght ;//初始存储容量为100  
    return OK;  
}  
/***********************在线性表第i个位置插入e*********************************/
Status insertList(SqList &L, ElemType e, int i){  
    ElemType *p,  *q;  
    if(i<0 ||i > L.lenght) return ERROR;  //i值不合法  
    if (L.lenght >= L.listsize) {  
        ElemType *newbase = (ElemType *)realloc(L.elem ,(L.listsize +LISTINCREMENT)*sizeof(ElemType));  
        if(!newbase) return OVERFLOW;   //存储分配失败    
        L.elem = newbase;               //新基值  
        L.listsize += LISTINCREMENT;    //增加存储容量  
    }  
    q = &L.elem[i];                     //q为插入的位置  
    for (p = &L.elem[L.lenght]; p>=q; --p) {  
        *p = *(p-1);                    //i元素之后的元素往后移动  
    }  
    *q = e;                             //插入e  
    L.lenght +=1;  
    return OK;  
  
} 
/********************删除线性表第i个位置，并用e返回其值****************************/
Status deleteListElem(SqList &L, int i, ElemType &e){  
    int *p,  *q;  
    if(i<0 ||i > L.lenght) return ERROR;  //i值不合法  
    q = &L.elem[i];                       //被删除元素的位置为i，L.elem就是数组名,  
    e = *q;                               //被删除元素的值赋值给e  
    for (p = q; p< (L.elem + L.lenght); p++){ //元素左移  
        *p = *(p+1);  
    }  
    --L.lenght;  
    return OK;  
}  
/*******************在顺序线性表L中查找第1个值与e满足compare()的元素的位序**********/
int LocateElem_Sq(SqList L,ElemType e,Status (*compare)(ElemType,ElemType)){	//若找到，则返回其在L中的位序，否则返回0
	i = 1;	// i的初值为第1个元素的位序
	p = L.elem
}
/********************合并两个线性表**********************************************/
void mergeList(SqList La, SqList Lb,  SqList &Lc){  
    ElemType *pa, *pb, *pc;  
    Lc.listsize =  La.lenght + Lb.lenght;  
    initList(Lc, Lc.listsize);          //初始化LC\pc = Lc.elem;  
    Lc.lenght = Lc.listsize;  
    pc = Lc.elem;  
    pa = La.elem;  
    pb = Lb.elem;  
    while (pa <= &La.elem[La.lenght -1] && pb <= &Lb.elem[Lb.lenght -1]){  
        if (*pa <= *pb) *pc++ = *pa++;  
        else *pc++ = *pb++;  
    }  
    while(pa <= &La.elem[La.lenght -1]) *pc++ = *pa++; //插入La的剩余元素  
    while(pb <= &Lb.elem[Lb.lenght -1]) *pc++ = *pb++; //插入Lb的剩余元素  
  
} 
int main(){

	return 0;
}