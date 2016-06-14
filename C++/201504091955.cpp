#include <stdio.h>    
#include "stdlib.h"  
#include <iostream>  
using namespace std;  
//�궨��    
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
/*     �ӿڣ� 
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
/* ��ջ  
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
/* ��ջ 
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
/* ��ȡջ��Ԫ������  
 
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
    printf("ջ�� ");  
    while (p) {  
        printf("%d ", p->data);  
        p = p->next;  
    }  
}  
/************************************************************************/  
/* �����һ�����ӣ�ֱ�Ӵ�X�Ƶ�Z���ɡ� 
�����n������Ҫ��X�Ƶ�Z��Y��Ϊ�������������ת��Ϊ���Ƚ�����n-1����X�ƶ���Y��Z��Ϊ������Ȼ�󽫵�n����X�ƶ���Z�����ʣ���n-1����Y�ƶ���Z��X��Ϊ������ 
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
    if(n==1) return move(X, Z);     //��Բ��1��ֱ���Ƶ�z  
    hanoi(n-1,X,Z,Y);               //��x�ϵ�1��n-1Բ���Ƶ�y��z��������  
    move(X, Z);                     //�����Ϊn��Բ����z  
    hanoi(n-1,Y,X,Z);               //��y�ϵ�1��n-1Բ���Ƶ�z��x��������  
}  
  
/************************************************************************/  
/* �ж�ջS�Ƿ��  
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
