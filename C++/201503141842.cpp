
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;
class Point
{
public:
	Point(){}
	Point(int m_x, int m_y):x(m_x),y(m_y){}
	int x;
	int y;
	friend ostream& operator<< (ostream &out, const Point &point);
};
/************************************************************************/
/* 函数功能：比较两个点（先以y坐标比较，若y相同按x比较）        */
/************************************************************************/
bool Cmp(const Point &left, const Point &right)
{
	return ((left.y < right.y) || ((left.y == right.y) && (left.x < right.x)));
}
/************************************************************************/
/* 函数功能：求两个向量的内积                                  */
/************************************************************************/
int CrossProduct(const Point &pre, const Point &cur, const Point &next)//pre是上一个点，cur是当前点，next是将要选择的点 
{
	int x1 = cur.x - pre.x;
	int y1 = cur.y - pre.y;
	int x2 = cur.x - next.x;
	int y2 = cur.y - next.y;
	return (x1*x2 + y1*y2); //<0是满足凸包的点
}
ostream& operator<< (ostream &out, const Point &point)
{
	out<<"("<<point.x<<","<<point.y<<")";
	return out;
}
/************************************************************************/
/* 函数功能：求两点间的距离                                    */
/************************************************************************/
int Distance(const Point &point1, const Point &point2)
{
	return (point1.x - point2.x)*(point1.x - point2.x) + (point1.y - point2.y)*(point1.y - point2.y);
}
/************************************************************************/
/* 函数功能：获取凸包
   参数vec存放输入的点，result存放凸包上的点*/
/************************************************************************/
void GetConvexHull(vector<Point> vec, vector<Point> &result)
{
	sort(vec.begin(), vec.end(), Cmp); //排序
	int size = vec.size();
	if(size < 3)
	{
		copy(vec.begin(), vec.end(), back_inserter(result));
	}
	else
	{
		result.push_back(vec.at(0));
		result.push_back(vec.at(1));
		result.push_back(vec.at(2));
		int top = 2;
		for(int i=3; i<size; i++)
		{
			while((top>0) && (CrossProduct(result.at(top-1), result.at(top), vec.at(i)) >= 0))
			{
				result.pop_back();
				top--;
			}
			result.push_back(vec.at(i));
			top++;
		}
	}
}
/************************************************************************/
/* 函数功能:卡壳算法（我也没搞懂）                             */
/************************************************************************/
int RotatingCalipers(vector<Point> vec, int n)
{
	int j = 1;
	int maxLength = 0;//存储最大值
	vec[n] = vec[0];
	for(int i = 0; i<n; i++)
	{
		while(CrossProduct(vec[i+1], vec[j+1], vec[i]) > CrossProduct(vec[i+1], vec[j], vec[i]))
			j = (j+1)%n;
		maxLength = max(maxLength, max(Distance(vec[i], vec[j]), Distance(vec[i+1], vec[j+1])));            
	}
	return maxLength; 
}
int main()
{
	vector<Point> vec;
	const int N = 20;
	int t,n,x,y;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>x>>y;
			vec.push_back(Point(x,y));
			cout<<"-----"<<endl;
		}
	}
	cout<<"平面上的点："<<endl;
	copy(vec.begin(), vec.end(), ostream_iterator<Point>(cout, "/n"));
	cout<<endl;
	vector<Point> result;
	GetConvexHull(vec, result);
	
	cout<<"凸包上的点："<<endl;
	copy(result.begin(), result.end(), ostream_iterator<Point>(cout, " "));
	cout<<endl;
	int distace = RotatingCalipers(result, result.size()-1);
	cout<<distace<<"-----------"<<endl;
	cout<<sqrt(double(distace))<<endl;
}
