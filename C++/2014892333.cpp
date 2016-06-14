#include<iostream> 
#include <string.h> 
using namespace std; 
#define max 200
int main() 
{  
	int a[max]={0},n,e,j,k,q,set=0;	//base的n次方  
	char c[20];//接收输入字符串  
	while(cin>>c>>n)  
	{   
		int len=strlen(c),base=0,i,record=0;   
		for(i=0;i<len;i++)   
		{    
			if(c[i]=='.')     
			{     
				record=len-i-1;//record为小数的位数     
				continue;     
			}      
			base=base*10+c[i]-'0';    
		}   
		if(record)   
		{    
			for(k=len-1;c[k]=='0';k--,record--)    
				base/=10;							//去掉后面多余的0;   
		}      
		record*=n;									//record为总的小数位
		for(q=base,i=0;i<max;i++,q/=10)   
		{    
			a[i]=q%10;								//把base复制到数组a        
		}       
		for(j=0;j<n-1;j++)   
		{    
			for(i=0;i<max;i++)    
			{     
				a[i]=a[i]*base+set;     
				set=a[i]/10;     
				a[i]=a[i]%10;      
			}    
		}											//计算,结果保存在数组a中      
		for(i=max-1;i>=0;i--)						//i是首个不为0的     
			if(a[i]!=0)
				break;          
		if(record>i)//无整数部分     
		{ 
			cout<<".";      
			for(e=record-1;e>=0;e--)     
			{      
				cout<<a[e];      
			}     
		}     
		else //有整数部分    
		{     
			for(;i>record-1;i--)     
			{      
				cout<<a[i];      
			}     
			if(i>=0)         
				cout<<".";           
			for(;i>=0;i--)       
				cout<<a[i];      
		}    
		cout<<endl;   
	}   
	return 0;  
}
