#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000];
int main(){
	int t,n,x;
   	cin>>t;
   	while(t--)
   	{
   		bool flag=true; 
        bool flag2=true;
        cin>>n;
        for(int i=0;i<n;i++)
       		cin>>a[i];
        for(int i=0;i<n;i++)
        {
        	cin>>x;
        	if(x!=a[i])
            	flag=false;
        	if(x!=a[n-i-1])
            	flag2=false;
        }
        if(flag2&&flag)
        	printf("both\n");
       	else if(flag)
        	printf("queue\n");
        else if(flag2)
        	printf("stack\n");
        else
        	printf("neither\n");
   }
	return 0;
}