#include <cstdio>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin("0.in");
    ofstream cout("0.out");
    stack<int> s;
    long long sum;
    int n,h,t;
    	cin>>n;
    	sum=0;
        cin>>h;
    	//scanf("%d",&h);
        s.push(h);
        for(int i=1;i<n;++i)
        {
            cin>>t;
            //scanf("%d",&t);
            while(!s.empty()&&t>=s.top())
                s.pop();
            sum+=s.size();
            //cout<<sum<<endl;
            s.push(t);
        }
        cout<<sum<<endl;
        //printf("%lld\n",sum);
        while(!s.empty())
            s.pop();   
    return 0;
}
