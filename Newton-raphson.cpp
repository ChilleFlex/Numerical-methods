#include<bits/stdc++.h>
#define EPSILON 0.001
using namespace std;


double func(double x)
{
    return x*x*x - x*x + 2;
}


double derivFunc(double x)
{
    return 3*x*x - 2*x;
}


void newtonRaphson(double x)
{

    double h = func(x) / derivFunc(x);


    while (abs(h) >= EPSILON)
    {
        //printf("\n%lf",func(x));
       // printf("\n%lf",derivFunc(x));

        h = func(x)/derivFunc(x);
        printf("\n%lf",h);

        x = x - h;
        printf("\n\n%lf",x);
    }



    printf("\t\n\n%lf",x);
}


int main()
{
    double x0 = -20;
    newtonRaphson(x0);
    return 0;
}
