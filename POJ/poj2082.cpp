#include <iostream>
#include <stack>
using namespace std;
#define M 50005
struct rectangle{
     int w,h;
}r[M];
int main(){
    int n;
    stack<rectangle> s;
    while (cin>>n&&n>0){
        int last=0,max=0;
        for (int i=0;i<n;i++){
            cin>>r[i].w>>r[i].h;
            if (r[i].h>=last)
                s.push(r[i]);
            else{
                int wide=0,area=0;
                while (!s.empty()&&s.top().h>r[i].h){
                    wide+=s.top().w;
                    area=wide*s.top().h;
                    if (area>max)
                        max=area;
                    s.pop();
                }
                r[i].w+=wide;
                s.push(r[i]);
            }
            last=r[i].h;
        }
        int wide=0,area=0;
        while (!s.empty()){
	    	wide+=s.top().w;
            area=wide*s.top().h;
            if (area>max)
                max=area;
            s.pop();
        }
	cout<<max<<endl;
    }
    return 0;
}
