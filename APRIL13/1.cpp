#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;

vector<long> items;

int main()
{
    int T, n, k;
    cin>>T;
    long tmp;
    while (T--)
    {
        items.clear();
        cin>>n>>k;
        LL sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin>>tmp;
            sum += tmp;
            items.push_back(tmp);
        }
        sort(items.begin(), items.end());
        LL d1 = 0;
        LL d2 = 0;
        for (int i = 0; i < k; ++i)
        {
            d1 += items[i];
            d2 += items[n-1-i];
        }
        cout<<max(abs(sum-d1-d1), abs(sum-d2-d2))<<endl;

    }

    return 0;
}

