#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 10005
struct point
{
	double x, y;
	void pr(){
		printf("%.2lf %.2lf\n", x, y);
	}
	point(){}
	point(double a, double b){
		x = a, y = b;
	}
	double best(){
		return -2*y/x;
	}
}p[N], list[N];
int stack[N], top;

int cross(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}    
double dis(point p1,point p2)
{
    return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}    
bool cmp(point p1,point p2) //极角排序函数，角度相同则距离小的在前面 
{
    int tmp=cross(list[0],p1,p2);
    if(tmp>0) return true;
    else if(tmp==0&&dis(list[0],p1)<dis(list[0],p2)) return true;
    else return false;
}
double r(double a, double b)
{
	return sqrt(pow(a,2)+pow(b,2));
}
void init(int n) //输入，并把最左下方的点放在 list[0]并且进行极角排序 
{
    int i,k;
    point p0;
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    list[0].x = r(a, b), list[0].y = c;
    p0.x=list[0].x;
    p0.y=list[0].y;
    k=0;
    for(i=1;i<n;i++)
    {
    	scanf("%lf%lf%lf", &a, &b, &c);
    	list[i].x =r(a, b), list[i].y = c;
        if( (p0.y>list[i].y) || ((p0.y==list[i].y)&&(p0.x>list[i].x)) )
        {
            p0.x=list[i].x;
            p0.y=list[i].y;
            k=i;
        }    
    }    
    list[k]=list[0];
    list[0]=p0;
    
    sort(list+1,list+n,cmp);
}     

void graham(int n)
{
    int i;
    if(n==1) {top=0;stack[0]=0;}
    if(n==2)
    {
        top=1;
        stack[0]=0;
        stack[1]=1;
    }    
    if(n>2)
    {
        for(i=0;i<=1;i++) stack[i]=i;
        top=1;
        
        for(i=2;i<n;i++)
        {
            while(top>0&&cross(list[stack[top-1]],list[stack[top]],list[i])<=0) top--;
            top++;
            stack[top]=i;
        }    
    }    
}
double cut(point p, point q)
{
	return (p.y-q.y)/(p.x-q.x);
}
double r2h(point p, double k)
{
	return pow(p.y-k*p.x, 3)/pow(k, 2);
}
void solve(int n)
{
	point A, B;
	A = B = point(0, 0);
	int a, b;
	for(int i = 0;i <= top;i++)
	{
		if(list[stack[i]].x > A.x)
		{
			A = list[stack[i]];
			a = i;
		}
		if(list[stack[i]].y > B.y)
		{
			B = list[stack[i]];
			b = i;
		}
	}
	double ans = 1e12;
	double r, h;
	if(a == b)
	{
		double k = list[stack[b]].best();
		r = list[stack[b]].x - list[stack[b]].y/k;
		h = list[stack[b]].y - list[stack[b]].x*k;
		printf("%.3f %.3f\n", h, r);
		return;
	}
	for(int i = a+1;i < b;i++)
	{
		double kk1 = cut(list[stack[i]], list[stack[i-1]]);
		double kk2 = cut(list[stack[i]], list[stack[i+1]]);
		double be = list[stack[i]].best();
		double k;
		if(fabs(be) < fabs(kk2))
			k = kk2;
		else if(fabs(kk1) < fabs(be))
			k = kk1;
		else
			k = be;
		double re = r2h(list[stack[i]], k);
		if(re < ans)
		{
			ans = re;
			r = list[stack[i]].x - list[stack[i]].y/k;
			h = list[stack[i]].y - list[stack[i]].x*k;
		}
	}
	double k1 = cut(list[stack[a]], list[stack[a+1]]);
	double k2 = cut(list[stack[b-1]], list[stack[b]]);
	double besta = list[stack[a]].best(), bestb = list[stack[b]].best();
	double k = k2;
	if(fabs(bestb) < fabs(k2))
		k = bestb;
	double re = r2h(list[stack[b]], k);
	if(re < ans)
	{
		ans = re;
		r = list[stack[b]].x - list[stack[b]].y/k;
		h = list[stack[b]].y - list[stack[b]].x*k;
	}

	k = k1;
	if(fabs(besta) > fabs(k1))
		k = besta;
	re = r2h(list[stack[a]], k);
	if(re < ans)
	{
		ans = re;
		r = list[stack[a]].x - list[stack[a]].y/k;
		h = list[stack[a]].y - list[stack[a]].x*k;
	}

	printf("%.3f %.3f\n", h, r);
	return;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		memset(p, 0, sizeof(p));
		scanf("%d", &n);
		init(n);
		graham(n);
		for(int i = 0;i < n;i++)
			list[i].pr();
		printf("--------\n");
		for(int i = 0;i <= top;i++)
			list[stack[i]].pr();
		printf("========\n");
		solve(n);
	}
	return 0;
}