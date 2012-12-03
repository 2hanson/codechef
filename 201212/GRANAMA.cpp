#include <iostream>
#include <string>
using namespace std;

const int maxn = 26;

int rc[maxn];
int sc[maxn];

int main()
{
    int test;
    cin>>test;
    string R, S;
    int i;
    int flag;
    while (test--)
    {
        for (i = 0; i < 26; ++i)
        {
            rc[i] = 0;
            sc[i] = 0;
        }

        cin>>R>>S;
        for (i = 0; i < R.size(); ++i)
        {
            ++rc[ R[i]-'a' ];
        }

        for (i = 0; i < S.size(); ++i)
        {
            ++sc[ S[i]-'a' ];
        }

        flag = 0;

        for (i = 0; i < 26; ++i)
        {
            if (rc[i] != sc[i])
            {
                if ( (0 == rc[i] || 0 == sc[i]) )
                {
                    flag = 2;
                }
                else if(0 == flag)
                {
                    flag = 1;
                }
            }

        }

        if (1 == flag)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }

    return 0;
}

