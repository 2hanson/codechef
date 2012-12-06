#include <iostream>
#include <stdio.h>
 
using namespace std;
#define LL long long
 
const LL Mod = 1000000007;
const LL MAXN = 100005;
LL segTreeMax[MAXN];
LL segTreeMin[MAXN];
 
int main()
{
    LL N;
    scanf("%lld", &N);
    LL temp;
    LL ans = 1;
 
    for (LL index = 1; index <= N; ++index)
    {
        scanf("%lld", &temp);
        
        segTreeMin[index] = segTreeMax[index] = temp;
 
        for (LL up = 1; up < index; ++up)
        {
            if (temp > segTreeMax[up])
            {
                segTreeMax[up] = temp;
            }
            else if (temp < segTreeMin[up])
            {
                segTreeMin[up] = temp;
            }
 
            ans *= (segTreeMax[up]-segTreeMin[up]);
 
            ans %= Mod;
        }
    }
 
    printf("%lld\n", ans);
    return 0;
}

