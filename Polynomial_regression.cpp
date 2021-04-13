#include <bits/stdc++.h>
#define MAX 10

using namespace std;

void normal(float x[], float y[], float c[MAX][MAX], float b[], int n, int m)
{
    int i, j, k, l1, l2;
    for (j =1; j <= m; j++)
    {
        for(k =1; k <= m; k++)
        {
            c[j][k] = 0.0;
            l1 = k+j-2;

            for(i=1; i<=n; i++)
            {
                c[j][k] = c[j][k] + pow(x[i], l1);
            }
        }
    }

    for(j=1; j<=m; j++)
    {
        b[j] = 0.0;
        l2 = j-1;
        for(i=1; i<=n; i++)
        {
            b[j] = b[j] + y[i] * pow(x[i], l2);
        }

    }
}

void gauss (int n, float a[MAX][MAX], float b[], float x[])
{
    int i, j, k;
    float pivot, factor, sum;

    for (k = 1; k <= n-1; k++)
    {
        pivot = a[k][k];
        for (i = k+1; i<= n; i++)
        {
             factor = a[i][k] / pivot;
             for (j = k+1; j <= n; j++)
             {
                 a[i][j] = a[i][j] - factor * a[k][j];
             }
             b[i] = b[i] - factor * b[k];
        }
    }
    x[n] = b[n]/a[n][n];
    for(k = n-1; k >=1 ; k--)
    {
        sum = 0.0;
        for (j = k +1; j<=n; j++)
        {
            sum = sum +  a[k][j] * x[j];
        }
        x[k] =(b[k] - sum) / a[k][k];
    }
}
int main ()
{
    int n, mp, m;
    float x[MAX], y[MAX], c[MAX][MAX], a[MAX], b[MAX];

    cout<<"\n   POLYNOMIAL REGRESSION \n"<<endl;

    ///reading values
    cout<<"Input number of data points n  "<<endl;
    cin>>n;
    cout<<"Input order of polynomial,mp required  "<<endl;
    cin>>mp;
    cout<<"Input data values, x and y\none set on each line\n"<<endl;

    for (int i = 1; i <= n; i++)
    {
        cin>> x[i] >> y[i];
    }

    ///testing the order
    if(n <= mp)
    {
        cout<<"\nRegression is not possible\n"<<endl;
        goto stop;
    }
    ///number of polynomial coefficients
    m = mp +1;

    normal(x, y, c, b, n, m);

    gauss (m, c, b, a);

    cout<<"Polynomial co-efficient:"<<endl;
    for(int i=1; i<=m; i++)
    {
        cout  <<a[i] << " ";
    }
    cout << endl;

    stop:
        cout << "END";

    return 0;

}
/***
4
2
1.0 2.0
2.1 2.5
3.2 3.0
4.0 4.0
