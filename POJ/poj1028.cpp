#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	stack<string> stack1,stack2;
    string str,s1,s2;  
    str="http://www.acm.org/";
    stack1.push(str);
	while(cin>>s1){
		if(s1=="QUIT")          
			break;
		if(s1=="VISIT")
		{
			cin>>s2;   
			cout<<s2<<endl;	    
			stack1.push(s2);  
			while(!stack2.empty())          
				stack2.pop();
		} 
		else
		{
			if(s1=="BACK")
			{
				if(stack1.size()>=2)
				{  
					stack2.push(stack1.top());      
					stack1.pop();
            		cout<<stack1.top()<<endl;	
				} 
				else                          
					puts("Ignored");
		  	} 
			else
			{
				if(!stack2.empty())
				{
					cout<<stack2.top()<<endl;
		        	stack1.push(stack2.top());  
					stack2.pop(); 	 
				} 
				else   	                    
					puts("Ignored");
			}
		}	
	}	
	return 0;
}
