#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int x;
    double y;
    cin>>x>>y;
    if (x % 5 == 0 && (double)x+0.5 <= y)
    {
        printf("%.2f\n", (y-0.5-(double)x));
        //cout<<y - 0.5 - (double)x<<endl;
    }
    else
    {
        printf("%.2f\n", y);
        //cout<<y<<endl;
    }

    return 0;
}
