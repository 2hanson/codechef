#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    int d = 33102;
    int tr = 103993 % d;
   
    while (T--)
    {
        int k;
        cin>>k;
        if (k == 0)
        {
            cout<<3<<endl;
            continue;
        }

        int r = tr;
        cout<<3<<".";
        while (k--)
        {
            r *= 10;
            cout<<r/d;
            r %= d;
        }
        cout<<endl;
    }

    return 0;
}
