#include<bits/stdc++.h>
using namespace std;
#define error 0.01

double f(double x)
{
    return x*x*x - x*x + 2;
}


void bisection(double a, double b)
{
    if (f(a)*f(b) >= 0)
    {
        printf("\nError interval ");
        return;
    }

    double c = a;
    while ((b-a) >= error)
    {
        c = (a+b)/2;

        if (f(c) == 0.0)
            break;

        else if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("\nRoot %lf",c);
}

int main()
{
    double a =-200, b = 300;
    bisection(a,b);
    return 0;
}










