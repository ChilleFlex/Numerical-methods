#include <bits/stdc++.h>
using namespace std;

float f(float x)
{
    float f = x*x*x + x -1;

    return f;
}

void secant(float x1, float x2, float E)
{
    float n = 0,xm,x0;

    if (f(x1) * f(x2) < 0) {
        do {

            x0 = (x1*f(x2) - x2*f(x1)) / (f(x2) - f(x1));


            float c = f(x1) * f(x0);

            x1 = x2;
            x2 = x0;

            n++;

            if (c == 0)
                break;

            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

        } while (fabs(xm - x0) >= E);



        printf("\nroot %f",x0);
        printf("\nitr %f",n);

    } else
        cout << "Can not find a root in the given inteval";
}

// Driver code
int main()
{
    float x1 = 0, x2 = 1, E = 0.0001;
    secant(x1, x2, E);
    return 0;
}
