#include <iostream>
#define ll unsigned long long
using namespace std;

ll ans;
ll n[3];

void init()
{
    ans = 0;
    for (int i = 0; i < 3; ++i)
    {
        cin>>n[i];
        ll temp = n[i];
        for (int k = 0; k < i; ++k)
        {
            if (n[i] < n[k])
            {
                for (int g = i; g > k; --g)
                {
                    n[g] = n[g-1];
                }
                n[k] = temp;
                break;
            }
        }
    }
}

void solve()
{
    ans = n[0]%(1000000007);
    ans = ans* (ll)( (n[1] - 1) % 1000000007);
    ans = ans % 1000000007;
    ans = ans*(ll) ( (n[2] - 2) % 1000000007);
    ans = ans % 1000000007;
}

void output()
{
    cout<<ans<<endl;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        init();
        solve(); 
        output();
    }
    return 0;
}

