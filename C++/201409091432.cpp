#include <stdio.h> 
#include <stack> 
using namespace std; 
 
 
struct Node 
{ 
    long long height;//һ���߶�ֵ 
    int startIdx; //����߶�ֵ����ʼλ�� 
 
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
 
    s.push(Node(-1, 0));//����С�߶ȼ����ջ����ֹ��ջ���� 
 
    int currentPosition; 
    long long maxArea = 0;//��¼������ 
    long long curArea; 
    for( i = 0; i <= nItem ; i++) 
    { 
        currentPosition = i + 1;//��õ�ǰ λ�� 
        if( i == nItem)//��ʱ��������Ϊ�����������Ҫ����ջ 
        { 
            height = 0; 
        } 
        else 
        { 
            height = gHeights[currentPosition-1]; 
        } 
        Node t(height, currentPosition);//��ǰ�ڵ� 
        while( s.top().height > height) 
        { 
            t = s.top(); 
            s.pop(); 
 
            curArea = (currentPosition - t.startIdx) * t.height;//����ĳ���߶ȵ� ��ʼ�ͽ�����λ�ã������� 
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
