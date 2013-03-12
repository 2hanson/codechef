#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin>>T;
    int L, W;
    while(T--)
    {
        cin>>L>>W;
        if (L > W)
        {
            cout<<1<<endl;
            continue;
        }
        double dis = 2.0*W/L;
        double br = 0;
        int ans = 0;
        while (br < dis)
        {
            ++ans;
            br += 1.0/(ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}

