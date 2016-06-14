#include <stdio.h> 
#include <stack> 
using namespace std; 
 
 
struct Node 
{ 
    long long height;//一个高度值 
    int startIdx; //这个高度值的起始位置 
 
    Node(long long _height, int _idx):height(_height), startIdx(_idx) 
    { 
 
    } 
}; 
long long gHeights[100000]; 
 
long long GetMaxArea(int nItem) 
{ 
    int i; 
    stack<Node> s; 
    long long height; 
 
    s.push(Node(-1, 0));//将最小高度加入堆栈，防止堆栈弹空 
 
    int currentPosition; 
    long long maxArea = 0;//记录最大面积 
    long long curArea; 
    for( i = 0; i <= nItem ; i++) 
    { 
        currentPosition = i + 1;//获得当前 位置 
        if( i == nItem)//这时候，我们认为到达最后，我们要弹空栈 
        { 
            height = 0; 
        } 
        else 
        { 
            height = gHeights[currentPosition-1]; 
        } 
        Node t(height, currentPosition);//当前节点 
        while( s.top().height > height) 
        { 
            t = s.top(); 
            s.pop(); 
 
            curArea = (currentPosition - t.startIdx) * t.height;//按照某个高度的 开始和结束的位置，获得面积 
            if(curArea > maxArea) 
            { 
                maxArea = curArea; 
            } 
        } 
        s.push(Node(height, t.startIdx)); 
 
    } 
    return maxArea; 
} 
int main() 
{ 
 
    int nItem; 
 
    while(scanf("%d", &nItem) != EOF) 
    { 
 
 
 
        int i; 
        for( i = 0; i < nItem; i++) 
        { 
            scanf("%lld", gHeights + i); 
        } 
        printf("%lld\n", GetMaxArea(nItem)); 
    } 
     
 
    return 0; 
 
} 
