#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <fstream>
using namespace std;
int fib(int n)       //¶ÓÁÐÊµÏÖ
{
	queue<int>q;
 	q.push(1);
 	q.push(1);
 	for(int i=2;i<n;i++)
 	{
  		q.push((q.front()%1000000+q.back()%1000000)%1000000);
  		q.pop();
 	}
 	return q.back();
}

int main()
{
	ifstream cin("9.in");
	ofstream cout("9.out");
	int n;
	cin>>n;
	cout<<fib(n)<<endl;	
	return 0;
}