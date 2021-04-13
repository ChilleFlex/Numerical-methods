#include<bits/stdc++.h>
using namespace std;
#define n 1000000


double f(double x)
{
    return x*x - 4*x - 10;
}


void falsePostion(double a,double b)
{
    if (f(a)*f(b) >= 0)
    {
        printf("\nError interval ");

        return;
    }

    double c = a;

    for (int i=0; i<n ; i++)
    {
        c = (a*f(b) - b*f(a))/ (f(b) - f(a));

        if (f(c)==0)
            break;

        else if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("\nroot : %lf ",c);
}

int main()
{
    double a =-2,b = -1;
    falsePosition(a,b);
    return 0;
}
