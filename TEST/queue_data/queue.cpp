#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

int main()
{
    stack<int> s;
    long long sum;
    int n,h,t;
    	scanf("%d",&n);
    	sum=0;
    	scanf("%d",&h);
        s.push(h);
        for(int i=1;i<n;++i)
        {
            scanf("%d",&t);
            while(!s.empty()&&t>=s.top())
                s.pop();
            sum+=s.size();
            //cout<<sum<<endl;
            s.push(t);
        }
        printf("%lld\n",sum);
        while(!s.empty())
            s.pop();   
    return 0;
}
