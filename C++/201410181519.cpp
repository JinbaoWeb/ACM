#include<iostream>
#define MAX 30001
using namespace std;
int main()
{
        int n;
        int data[MAX];
        int num1 = 0, min;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
                cin>>data[i];
           if(1 == data[i])     num1++;
        }
        min = num1;
        for(int i = 0; i < n; ++i)             //����ÿ���ָ�λi�����Ǽ��㣨numOF1-n1)+n2��  Ȼ�����С�ĸ�min     
        {
                if(1 == data[i]) num1--;                       //numOF1��ȥiλǰ��1 �ĸ���ͬʱ��
                                                                          //��2�ĸ�����Ҳ��    �� ��numOF1-n1)+n2
                else num1++;
                if(num1 < min) min = num1;                 //����С�ĸ�min
        }
        cout<<min<<endl;
        return 0;
}
 
