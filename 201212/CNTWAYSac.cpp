/*
// Lucas定理求解C(n,k)%p, p是素数
// C(n,k)%p = C(n%p,k%p)*C(n/p,k/p)%p
// C(n,k)%p = n!/(k!*(n-k)!)%p = n!*((k!*(n-k)!)^(p-2))%p
// pow_mod(a,b,p)求a^b%p的值, 快速幂取模算法
// com_mod(n,k,p)求C(n,k)%p的值
// lucas(n,k,p)使用lucas定理求C(n,k)%p的值
*/

#include <algorithm>
#include <deque>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define fr(i,m,n) for(int i=m; i<=n; ++i)
#define ff first.first
#define fs first.second
#define ss second.second
#define sf second.first

const long long Mod = 1000000007; 
#define LL long long

typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef set<int> si;
typedef vi::iterator vitr;
typedef list<int> li;
typedef li::iterator litr;
typedef vector< vector< ii > > graph;
 
#define MOD 1000000007
 
int fact[800001], invfact[800001];
 
int powmod(int base, int expo){
	if(expo==0)
		return 1;
	else if(expo&1)
		return (long long)base*powmod(base, expo-1)%MOD;
	else{
		int root=powmod(base, expo>>1);
		return (long long)root*root%MOD;
	}
}
 
int inverse(int x){
	return powmod(x, MOD-2);
}
 
void init(){
	fact[0]=1;
	for(int i=1; i<=800000; i++)
		fact[i]=(long long)i*fact[i-1]%MOD;
	invfact[800000]=inverse(fact[800000]);
	for(int i=800000; i>0; i--)
		invfact[i-1]=(long long)i*invfact[i]%MOD;
}
 
long long nCr(int n, int r){
	
}

LL Lucas(LL a,LL b,LL p)
{
LL n = a;
LL r = b;
	if(r>n || r<0)
		return 0;
	return (long long)((long long)fact[n]*invfact[r]%MOD)*invfact[n-r]%MOD;

}
 
int main()
{
    init();
   /* for (long index = 4005; index <= 800000; ++index)
    {
        Table[index] = Table[index-1]*index;
        Table[index] %= Mod;
    }
 */
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
