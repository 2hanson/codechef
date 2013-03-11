#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const long maxn = 100005;
long N, K;
double rdf[maxn][35];

void input()
{
    scanf("%ld %ld", &N, &K);
}

void output()
{
    printf("%lf\n", rdf[N][K]);
}

void init()
{
    memset(rdf, 0, sizeof(rdf));    

    for (int i = 0; i <= 100000; ++i)
    {
        rdf[i][0] = i;
    }
    for (int i = 0; i < 35; ++i)
    {
        rdf[0][i] = 0;
    }

    for (int oi = 1; oi <= 100000; ++oi)
    {
        for (int ii = 1; ii < 35; ++ii)
        {
            rdf[oi][ii] = ( rdf[oi-1][ii-1] + (oi-1)*rdf[oi-1][ii] )/oi;
        }
    }
}

int main()
{
    long T;
    scanf("%ld", &T);
    init();
    while (T--)
    {
        input();
        if (K >= 35)
        {
            cout<<"0"<<endl;
            continue;
        }
        output();
    }

    return 0;
}

