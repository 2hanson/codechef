#include <iostream>
#include <stdio.h>
using namespace std;

const long long Mod = 1000000007;

int main()
{
    freopen("out.txt", "w", stdout);
    long long res = 1;
    for (long i = 2; i <= 4005; ++i)
    {
        res = res * i;
        res = res % Mod;
        printf(", %lld", res);
    }
    printf("\n");

    return 0;
}
