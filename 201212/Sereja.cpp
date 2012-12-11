#include <iostream>
#include <stdio.h>
 
using namespace std;
#define LL long long
 
const LL Mod = 1000000007;
const LL MAXN = 100005;
LL segTreeMax[MAXN];
LL segTreeMin[MAXN];
LL C[MAXN];

int main()
{
    LL N;
    scanf("%lld", &N);
    LL temp;
    LL ans = 1;
    LL up, upL;
    C[0] = 1;

    for (LL index = 1; index <= N; ++index)
    {
        scanf("%lld", &temp);
        
        segTreeMin[index] = segTreeMax[index] = temp;
 
        for (up = index - 1; up&&segTreeMin[up]>temp; --up)
            segTreeMin[up] = temp;
        upL = up;

        for (up = index - 1; up&&segTreeMax[up]<temp; --up)
            segTreeMax[up] = temp;
        
        if (upL > up)
            upL = up;

        upL += (upL == 0);
        for (up = upL; up < index; ++up)
        {
            C[up] = C[up-1]*(segTreeMax[up]-segTreeMin[up])%Mod;
        }
        ans = ans * C[index-1]%Mod;
/*
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
        }*/
    }
 
    printf("%lld\n", ans);
    return 0;
}
