/*
// Lucas定理求解C(n,k)%p, p是素数
// C(n,k)%p = C(n%p,k%p)*C(n/p,k/p)%p
// C(n,k)%p = n!/(k!*(n-k)!)%p = n!*((k!*(n-k)!)^(p-2))%p
// pow_mod(a,b,p)求a^b%p的值, 快速幂取模算法
// com_mod(n,k,p)求C(n,k)%p的值
// lucas(n,k,p)使用lucas定理求C(n,k)%p的值
*/

#include <iostream>
#include <stdio.h>
using namespace std;
 
const long long Mod = 1000000007; 
#define LL long long

LL Table[800005] = {1, 1, };

inline LL fast(LL a,LL b,LL p)
{
    LL s=1;
    while(b)
    {
        if(b&1)
        {
            s=(s*a);
            if (s > p)
            {
                s = s % p;
            }
            else if (s == p)
            {
                s = 0;
            }
        }
        b=b>>1;
        a=(a*a);
        if (a > p)
        {
            a = a % p;
        }
        else if (a == p)
        {
            a = 0;
        }
    }
 
    return s;
}
 
LL cal(LL a,LL b,LL p)
{
    if(a<b) return 0;
    if(b>a-b) b=a-b;
 
    long long coma=Table[a]*fast((Table[b]*Table[a-b])%p, p-2, p);
 
    if (coma > p)
    {
        coma = coma % p;
    }
    else if (coma == p)
    {
        coma = 0;
    }
    
    return coma;
}
 
LL Lucas(LL a,LL b,LL p)
{
    LL ans=1;
    while(a&&b&&ans)
    {
        ans=ans*cal(a%p,b%p,p);
        a=a/p;
        b=b/p;
    }
 
    return ans;
}
 
int main()
{
    for (int i = 0; i < 5; ++i)
        cout<<Table[i]<<endl;

    int R;
    scanf("%d", &R);
    long long n, m, a, b;
    long long ans;
    
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
            long long CXY1;
            long long CXY2;
            //ans = (Combination(n+m, sT));
            ans = Lucas(n+m, n, Mod); 
            
            a2 = n - a + 1;
            b2 = b - 1;
            for (long long tx = 0; ; ++tx)
            {
                long long x = a2 + tx;
                long long y = b2 - tx;
                if (x > n)
                    break;
                if (y < 0)
                    break;
                    
                CXY1 = Lucas(x+y, y, Mod);//Combination(x+y, sT);
                CXY2 = Lucas(n-x+m-y, m-y, Mod);
                
                CXY1 %= Mod;
                CXY2 %= Mod;

                long long temp = CXY1 * CXY2;

                if (temp > Mod)
                {
                    temp = temp % Mod;
                }
                else if (temp == Mod)
                {
                    temp = 0;
                }
 
                ans -= temp;
                while (ans < 0)
                {
                    ans += Mod;
                }
            }
        }
        else
        {
            long long CXY1;
            long long CXY2;
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

                //cout<<x<<" "<<y<<endl;
                    
                CXY1 = Lucas(x+y, x, Mod);//Combination(x+y, sT);
                CXY2 = Lucas(n-x+m-y, n-x, Mod);

                CXY1 %= Mod;
                CXY2 %= Mod;

                long long temp = CXY1 * CXY2;
 
                if (temp > Mod)
                {
                    temp = temp % Mod;
                }
                else if (temp == Mod)
                {
                    temp = 0;
                }
 
                ans += temp;
                if (ans >= Mod)
                {
                    ans = ans % Mod;
                }
            }
        }
 
        if (ans >= Mod)
            ans = ans % Mod;
        else if (ans < 0)
        {
            ans += Mod;
        }
        printf("%lld\n", ans);
    }
 
    return 0;
}
