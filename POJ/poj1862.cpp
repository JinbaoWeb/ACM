/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-16 23:32
 * Filename :        poj1862.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main(){
	int n,i;
	double a,b,t;
	priority_queue<double> pq;
	cin>>n;
	for(i = 0; i < n; i++){
		cin>>t;
		pq.push(t);
	}

	while(pq.size() > 1){
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		t = 2 * sqrt(a * b);
		pq.push(t);
	}
	//printf("%.3lf\n",pq.top()); 采用C++的写法
	cout.setf(ios::fixed);
	cout.precision(3);
	cout << pq.top() << endl;
	return 0;
}
