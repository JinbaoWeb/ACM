#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
const double Pi = acos(-1.0);
double f(double x)
{
    return 0.25*sin(2*x)+2*sin(x)+4.5*x;
}

double g(double x)
{
    return (2.0+cos(x))*sqrt(1.0+sin(x)*sin(x));
    //return x;
}
double simpson(double a, double b, int n)
{
    double h = (b-a)/n;
    double ans = g(a)+g(b);
    for(int i = 1;i < n;i+=2) ans += 4*g(a+i*h);
    for(int i = 2;i < n;i+=2) ans += 2*g(a+i*h);
    return ans*h/3;
}
double romberg(double a, double b, double eps = 1e-8)
{
    vector <double>t;
    double h = b-a, last, curr;
    int k = 1, i = 1;
    t.push_back(h*(g(a)+g(b))/2.0);
    do{
        last = t.back();
        curr = 0;
        double x = a+h/2.0;
        for(int j = 0;j < k;j++)
        {
            curr += g(x);
            x += h;
        }
        curr = (t[0]+h*curr)/2.0;
        double k1 = 4.0/3.0, k2 = 1.0/3.0;
        for(int j = 0;j < i;j++)
        {
            double temp = k1*curr - k2*t[j];
            t[j] = curr;
            curr = temp;
            k2 /= 4*k1-k2;
            k1 = k2+1;
        }
        t.push_back(curr);
        k *= 2;
        h /= 2;
        i++;
    }while(fabs(last-curr) > eps);
    return t.back();
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        double a, b;
        scanf("%lf%lf", &a, &b);
        double S = M_PI*(2+cos(a))*(2+cos(a));
        /*
        if(a > b)
        {
            double t = a;
            a = b;
            b = a;
        }
        */
        double V = f(b)-f(a);
        V *= M_PI;

        S += romberg(a, b)*2*M_PI;

        printf("%.6f %.6f\n", V, S);
    }
    return 0;
}