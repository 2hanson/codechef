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
 
LL CB[10005][10005];
 
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
    LL ans=1,coma=1,comb=1;
    
    if (a < 10005 && b < 10005 && CB[a][b] != 0)
        return CB[a][b];
 
    if (a-1>=0 && a-1<10005 && b-1>=0&&b<10005 && CB[a-1][b]!=0 && CB[a-1][b-1]!=0)
    {
        CB[a][b] = CB[a-1][b-1]+CB[a-1][b];
        return CB[a][b];
    }
 
    for(LL i=0;i<b;i++)
    {
        coma=(coma*(a-i));
        if (coma > p)
        {
            coma = coma % p;
        }
        else if (coma == p)
        {
            coma = 0;
        }
 
        comb=(comb*(b-i));
        if (comb > p)
        {
            comb = comb % p;
        }
        else if (comb == p)
        {
            comb = 0;
        }
    }
     
    coma=coma*fast(comb,p-2,p);
 
    if (coma > p)
    {
        coma = coma % p;
    }
    else if (coma == p)
    {
        coma = 0;
    }
    
    if (a < 10005 && b < 10005)
        CB[a][b] = coma;
 
    return coma;
}
 
LL Lucas(LL a,LL b,LL p)
{
    LL ans=1;
    if (a < 10005 && b < 10005 && CB[a][b] != 0)
        return CB[a][b];
 
    if (a-1>=0 && a-1<10005 && b-1>=0&&b<10005 && CB[a-1][b]!=0 && CB[a-1][b-1]!=0)
    {
        CB[a][b] = CB[a-1][b-1]+CB[a-1][b];
        return CB[a][b];
    }
    while(a&&b&&ans)
    {
        ans=ans*cal(a%p,b%p,p);
        a=a/p;
        b=b/p;
    }
 
    if (a < 10005 && b < 10005)
        CB[a][b] = ans;
    return ans;
}
 
int main()
{
    int R;
    scanf("%d", &R);
    long long n, m, a, b;
    long long ans;
    CB[1][1] = 1;
    CB[2][1] = 2;
    CB[2][2] = 1;
    
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
            //ans = (Combination(n+m, sT));
            ans = Lucas(n+m, n, Mod);
            for (long long tx = a; tx >= 1; --tx)
            {
                long long ty = tx;
                if (ty > b)
                    continue;
 
                long long x = n - a + tx;
                long long y = b - ty;
 
                long long temp = Lucas(x+y, x, Mod);//Combination(x+y, sT);
 
                temp = (temp*( Lucas(n-x+m-y, n-x, Mod) ));
 
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
 
                long long temp = Lucas(x+y, x, Mod);
 
                temp = (temp*( Lucas(n-x+m-y, n-x, Mod) ));
 
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
        printf("%lld\n", ans);
    }
 
    return 0;
}
