#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
using namespace std;

const long long M = 1000000007; 
long long ff[800005];  //打表，记录n!，避免重复计算
long long comb[10009][10009];

//求最大公因数
long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

//解线性同余方程，扩展欧几里德定理
long long x,y;
void Extended_gcd(long long a, long long b)
{
    if(b==0)
    {
       x=1;
       y=0;
    }
    else
    {
       Extended_gcd(b,a%b);
       long long t=x;
       x=y;
       y=t-(a/b)*y;
    }
}

//计算不大的C(n,m)
long long C(long long a, long long b)
{

    if(b>a)
        return 0;
   
    if ( a < 10009 && b < 10009 && comb[a][b] != 0)
        return comb[a][b];

    if (a-1 > 0 && a-1 < 10009 && b < 10009 && b-1 > 0 && comb[a-1][b] != 0 && comb[a-1][b-1]!=0)
    {
        return (comb[a][b] = comb[a-1][b-1]+comb[a-1][b]);
    }

    b=(ff[a-b]*ff[b])%M;
    a=ff[a];
    long long c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+M)%M;
    x=(x*a)%M;
    
    if ( a < 10009 && b < 10009)
        comb[a][b] = x;
    return x;
}

//Lucas定理
long long Combination(long long n, long long m)
{
    if (m == 0)
        return 1;
    if (m == n)
        return 1;
    if (m < 0 || m > n)
        return 0;

    if ( m < 10009 && n < 10009 && comb[n][m] != 0)
        return comb[n][m];
    
    if (n - 1 > 0 && n-1 < 10009 && m < 10009 && m-1 > 0 && comb[n-1][m] != 0 && comb[n-1][m-1]!=0)
    {
        return (comb[n][m] = comb[n-1][m-1]+comb[n-1][m]);
    }
    long long ans=1;
    long long a,b;
    while(m||n)
    {
        a=n%M;
        b=m%M;
        n/=M;
        m/=M;
        ans=(ans*C(a,b))%M;
    }
        

    if ( n < 10009 && m < 10009)
        comb[n][m] = ans;
    return ans;
}

int main()
{
    int R;
    scanf("%d", &R);
    long long n, m, a, b;
    long long ans, sT;
    ff[0]=1;
    for(long long i=1;i<= 800004;i++)  //预计算n!
    {
        ff[i]=(ff[i-1]*i)%M;
    }

    while (R--)
    {
        scanf("%lld %lld %lld %lld", &n, &m, &a, &b);   
        long long a2 = n - a;
        long long b2 = m - b;
        long long mab = a;
        long long mab2 = a2;
        if (a > b)
            mab = b;
        if (a2 > b2)
            mab2 = b2;

        if (mab2 > mab)
        {
            sT = n;
            if (sT > m)
                sT = m;
            ans = (Combination(n+m, sT));

            for (long long tx = a; tx >= 1; --tx)
            {
                long long ty = tx;
                if (ty > b)
                    continue;

                long long x = n - a + tx;
                long long y = b - ty;

                sT = x;
                if (x > y)
                    sT = y;
                long long temp = Combination(x+y, sT);

                sT = n-x;
                if (n-x > m-y)
                    sT = m - y;
                temp = (temp*( Combination(n-x+m-y, sT) ))%M;

                ans -= temp;
                while (ans < 0)
                {
                    ans += M;
                }
            }
        }
        else
        {
            ans = 0;
            a2 = n - a;
            b2 = b;
            for (long long tx = 0; ; ++tx)
            {
                long long x = a2 - tx;
                long long y = b2 + tx;
                if (x < 0)
                    break;
                if (y > m)
                    break;

                sT = x;
                if (x > y)
                    sT = y;
                long long temp = Combination(x+y, sT);

                sT = n-x;
                if (n-x > m-y)
                    sT = m - y;
                temp = (temp*( Combination(n-x+m-y, sT) ))%M;

                ans += temp;
                if (ans > M)
                {
                    ans = ans % M;
                }
            }
        }

        if (ans >= M)
            ans = ans % M;
        printf("%lld\n", ans);
    }
    return 0;
}

