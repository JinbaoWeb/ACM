#include<stdio.h> 
#include <iostream>
using namespace std;  
#define N 16   
int n; //�ʺ����   
int sum = 0; //���н����   
int x[N]; //�ʺ���õ�����   
  
int abs(int a)
{
	if (a>0)
		return a;
	else
		return -a;
} 
int place(int k)   
{   
    int i;   
    for(i=1;i<k;i++)   
      if(abs(k-i)==abs(x[k]-x[i]) || x[k] == x[i])   
        return 0;   
    return 1;   
}   
int queen(int t)   
{   
    if(t>n && n>0) //�����õĻʺ󳬹�nʱ�����н������1����ʱn�������0   
      sum++;   
    else  
      for(int i=1;i<=n;i++)   
      {   
          x[t] = i; //������t���ʺ���ڵ�i��   
          if(place(t)) //������Է���ĳһλ�ã����������һ�ʺ�   
            queen(t+1);    
      }   
    return sum;   
}   
  
int main()   
{   
    int t;   
    while(cin>>n){
       
    t = queen(1);   
    if(n == 0) //���n=0������н����Ϊ0���������һ����Ҫ����   
      t = 0;   
    cout<<t<<endl;
	}
    return 0;   
}  
