#include <iostream>
using namespace std;

const int maxn = 25;
int N, K, M;
int r[maxn];
int temp[maxn];
int ans;

void test()
{
    for (int i = 0; i < N; ++i)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

void init()
{
    cin>>N>>K>>M;
    for (int i = 0; i < N; ++i)
    {
        cin>>r[i];
    }
}

bool isOK(int cur)
{
    int i;
    int num = 0;
    int maxV = 0;
    for (i = cur; i <= cur+K-1; ++i)
    {
        if (temp[i] == maxV)
        {
            ++num;
        }
        else if (temp[i] > maxV)
        {
            num = 1;
            maxV = temp[i];
        }
    }

    return (num < M);
}

bool noarrest()
{
    for (int i = 0; i <= N-K; ++i)
    {
        if (false == isOK(i))
            return false;
    }

    return true;
}

void solve()
{
    ans = -1;
    for (long k = 0; k < (1<<N); ++k)
    {
        int tans = 0;
        for (int i = 0; i < N; ++i)
        {
            long cur = 1 << i;
            if (k & cur)
            {
                ++tans;
                temp[i] = r[i]+1;
            }
            else
            {
                temp[i] = r[i];
            }
        }

        if (ans != -1 && tans > ans)
        {
            continue;
        }

        if (true == noarrest())
        {
            if (ans == -1 || tans < ans)
            {
                ans = tans;
            }
        }
    }

    return;
}

void output()
{
    cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        init();

        solve();
        output();
    }

    return 0;
}

