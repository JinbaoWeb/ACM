#include <stdio.h>    
#include "stdlib.h"  
#include <iostream>  
using namespace std;  
//宏定义    
#define TRUE   1    
#define FALSE   0    
#define OK    1    
#define ERROR   0    
#define INFEASIBLE -1    
#define OVERFLOW -2   
#define STACKEMPTY -3    
  
#define LT(a,b)   ((a)<(b))    
#define N = 100           
  
typedef int Status;    
typedef int ElemType;    
  
typedef struct LNode{    
    ElemType        data;                 
    struct LNode   *next;       
}LNode, *LinkList;   
  
typedef struct stack{  
    LinkList top;  
} STACK;  
  
  
/************************************************************************/  
/*     接口： 
*/  
/************************************************************************/  
void InitStack(STACK &S);  
void Push(STACK &S,ElemType e);  
void Pop(STACK &S, ElemType *e);  
ElemType GetTop(STACK S,ElemType *e);  
int StackEmpty(STACK S);  
  
/************************************************************************/  
/*  
*/  
/************************************************************************/  
void InitStack(STACK &S)  
{  
    S.top=NULL;  
}  
  
/************************************************************************/  
/* 入栈  
*/  
/************************************************************************/  
void Push(STACK &S,ElemType e)  
{  
    LinkList p;  
    p = (LinkList )malloc(sizeof(LNode));  
    if (!p) exit(OVERFLOW);  
    p->data = e;  
    p->next = S.top;  
    S.top = p;  
}  
/************************************************************************/  
/* 出栈 
*/  
/************************************************************************/  
void Pop(STACK &S, ElemType *e)  
{  
    LinkList p;  
    if(StackEmpty(S)) exit(STACKEMPTY);  
    *e = S.top->data;  
    p = S.top;  
    S.top = p->next;   
    free(p);  
}  
/************************************************************************/  
/* 获取栈顶元素内容  
 
*/  
/************************************************************************/  
ElemType GetTop(STACK S, ElemType *e)  
{  
    if(StackEmpty(S)) exit(STACKEMPTY);  
    *e = S.top->data;  
}  
void printStack(STACK S){  
    LinkList p;  
    p = S.top;  
    printf("栈： ");  
    while (p) {  
        printf("%d ", p->data);  
        p = p->next;  
    }  
}  
/************************************************************************/  
/* 如果有一个盘子，直接从X移到Z即可。 
如果有n个盘子要从X移到Z，Y作为辅助。问题可以转化为，先将上面n-1个从X移动到Y，Z作为辅助，然后将第n个从X移动到Z，最后将剩余的n-1个从Y移动到Z，X作为辅助。 
*/  
/************************************************************************/  
  
void move(STACK &Sa,STACK &Sb)  
{     
    ElemType e;  
    Pop(Sa,&e);  
    Push(Sb, e);  
}  
void hanoi(int n,STACK  &X,STACK &Y,STACK &Z)  
{  
    if(n==1) return move(X, Z);     //将圆盘1号直接移到z  
    hanoi(n-1,X,Z,Y);               //将x上的1大n-1圆盘移到y，z做辅助塔  
    move(X, Z);                     //将编号为n的圆盘移z  
    hanoi(n-1,Y,X,Z);               //将y上的1大n-1圆盘移到z，x做辅助塔  
}  
  
/************************************************************************/  
/* 判断栈S是否空  
*/  
/************************************************************************/  
int StackEmpty(STACK S)   
{  
    if(S.top==NULL) return TRUE;  
    return   FALSE;  
}  
  
int main()    
{    
  
    STACK Sx, Sy,Sz;  
    InitStack( Sx);  
    InitStack( Sy);  
    InitStack( Sz);  
    int i, n = 10;  
    for (i = 10 ; i>=1 ;i--) {  
        Push(Sx, i);  
    }  
    printStack(Sx);  
    hanoi(n,  Sx,Sy,Sz);  
    printStack(Sz); 
	return 0; 
}    
