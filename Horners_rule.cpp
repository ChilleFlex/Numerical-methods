#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100];
int prr[100];
int n;

double f(double x)
{
    double res=arr[n];
    for(int i=n-1;i>=0;i--)
    {
        res=res*x+arr[i];
    }
    return res;
}

double fp(double x)
{
    double res=prr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        res=res*x+prr[i];
    }
    return res;
}

int main()
{
    int i,j;
    double x0,x1;
    double error = .001;

    cout<<"enter degree: ";
    cin>>n;

    for(i=n;i>=0;i--)
    {
        cout<<"enter a"<<i<<endl;
        cin>>arr[i];
    }

    for(i=n-1;i>=0;i--)
    {
        cout<<"enter prime"<<endl;
        cin>>prr[i];
    }

    cout<<"enter value";
    cin>>x0;

    printf("%f",f( x0));

    return 0;
}
