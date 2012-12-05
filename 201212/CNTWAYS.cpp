#include <iostream>
#include <stdio.h>
using namespace std;
 
const long long Mod = 1000000007; 
#define LL long long
 
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
 
                if (tx == 0)
                {
                    CXY1 = Lucas(x+y, y, Mod);//Combination(x+y, sT);
                    CXY2 = Lucas(n-x+m-y, m-y, Mod);
                }
                else
                {
                    if (y == 0 || x == 0)
                    {
                        CXY1 = 1;
                    }
                    else
                    {
                        CXY1 = CXY1 * (y+1) / x;
                    }
                    if (n-x == 0 || m-y == 0)
                    {
                        CXY2 = 1;
                    }
                    else
                    {
                        CXY2 = CXY2 * (n-x+1) / (m-y);
                    }
                }
                
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

                if (tx == 0)
                {
                    CXY1 = Lucas(x+y, x, Mod);//Combination(x+y, sT);
                    CXY2 = Lucas(n-x+m-y, n-x, Mod);
                }
                else
                {
                    //pre C(x+y, x+1), now C(x+y, x);
                    if (y == 0 || x == 0)
                    {
                        CXY1 = 1;
                    }
                    else
                    {
                         CXY1 = CXY1 * (x+1) / y;
                    }
                    //pre C(n-x+m-y, n-x), now C(n-x+m-y, );
                   if (m - y == 0 || n-x == 0)
                   {
                        CXY2 = 1;
                   }
                   else
                   {
                        CXY2 = CXY2 * (m-y+1) / (n-x);
                    }
                }

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
