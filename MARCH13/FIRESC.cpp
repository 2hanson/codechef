#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;
 
const long mod = 1000000007;
const long maxn = 100005;
long p[maxn];
long sum[maxn];
long n, m;
long long r, c;
 
void init()
{
    for (int i = 1; i <= n; ++i)
    {
        p[i] = -1;
        sum[i] = 1;
    }
}
 
void solve()
{
    r = 0;
    c = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == -1)
        {
            ++r;
            c *= sum[i];
            c %= mod;
        }
    }
}
 
void output()
{
    cout<<r<<" "<<c<<endl;
}
 
int main()
{
    int T;
    cin>>T;
    long i, j;
    while (T--)
    {
        cin>>n>>m;
        init();
        while (m--)
        {
            scanf("%ld %ld", &i, &j);
            
            while (p[i] != -1)
            {
                i = p[i];
            }
            while (p[j] != -1)
            {
                j = p[j];
            }
 
            if (i == j)
                continue;

            if (sum[i] > sum[j])
            {
                p[j] = i;
                sum[i] += sum[j];
            }
            else
            {
                p[i] = j;
                sum[j] += sum[i];
            }
        }
        solve();
        output();
    }
    return 0;
}
 
