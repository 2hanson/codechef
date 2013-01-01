#include <iostream>
using namespace std;

const int maxn = 105;
long salary[maxn];
long smallest;

int main()
{
    int T;
    cin>>T;
    long ans;
    while (T--)
    {
        smallest = 10001;
        int N;
        cin>>N;
        
        for (int i = 1; i <= N; ++i)
        {
            cin>>salary[i];
            if (salary[i] < smallest)
            {
                smallest = salary[i];
            }
        }

        long ans = 0;
        for (int i = 1; i <= N; ++i)
        {
            ans += (salary[i] - smallest);
        }

        cout<<ans<<endl;
    }
    return 0;
}

