#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
    long T;
    cin>>T;
    while (T--)
    {
        long double ds, dt, d;
        cin>>ds>>dt>>d;
        long double ans = 0;
        if (ds > (d + dt))
        {
            ans = ds-(d+dt);
        }
        else if (dt > (d + ds))
        {
            ans = dt - (d+ds);
        }
        else
        {
            ans = d - (dt+ds);
        }
        if (ans < 0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }

    }
    return 0;
}

