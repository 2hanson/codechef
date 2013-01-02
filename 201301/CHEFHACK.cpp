#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

const long limit = 10000001;
const int maxn = 355;
long server[maxn][maxn];
int N;
int isp[limit] = {0};
vector<long> primes;
long long ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void get_primes()
{
    isp[0] = 1;
    isp[1] = 1;

    for (long cur = 2; cur < limit; ++cur)
    {
        if (isp[ cur ] == 0)
        {
            primes.push_back( cur );
            for (long skip = cur<<1; skip < limit; skip += cur)
            {
                isp[ skip ] = 1;
            }
        }
    }
}

void init()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            scanf("%ld", &server[i][j]);
        }
    }
    ans = 0;
}

long bin_search(long p)
{
    long mid;
    long left = 0;
    long right = primes.size() - 1;
    while (left <= right)
    {
        mid = (left + right)/2;
        if (primes[mid] == p)
        {
            return mid;
        }
        else if (primes[mid] > p)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int isvalid(int x, int y)
{
    if (x < 1)
        return 0;
    if (y < 1)
        return 0;
    if (x > N)
        return 0;
    if (y > N)
        return 0;

    return 1;
}

void grid_hack(int x, int y, int mode)
{
    int curx, cury;
    for (int i = 0; i < 4; ++i)
    {
        curx = dx[i] + x;
        cury = dy[i] + y;
        if (isvalid(curx, cury) == 0)
            continue;

        if (server[curx][cury] == -1)
        {
            continue;
        }
        //prime
        if (isp[ server[curx][cury] ] == 0)
            continue;

        if ( server[curx][cury]%2 != mode)
            continue;
        
        server[curx][cury] = -1;
        grid_hack(curx, cury, mode);
    }
}

void solve()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (server[i][j] == -1)
            {
                continue;
            }
            long password = server[i][j];
            server[i][j] = -1;
            //prime
        
            if (isp[ password ] == 0)
            {
                ans += bin_search(password);
            }
            else
            {
                if (password % 2 == 0)
                {
                    ans += password/2;
                    grid_hack(i, j, 0);
                }
                else
                {
                    ++password;
                    ans += (password/2 + 1);
                    grid_hack(i, j, 1);
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    primes.clear();
    memset(isp, 0, sizeof(isp));
    get_primes();
    while (T--)
    {
        init();
        solve();
        printf("%lld\n", ans);
    }
    return 0;
}

