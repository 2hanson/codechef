#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 105;
long S[maxn][maxn];

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin>>S[i][j];
        
                if (i == 1)
                {
                    S[i][j] += S[i][j-1];
                }
                else if (j == 1)
                {
                    S[i][j] += S[i-1][j];
                }
                else if (S[i][j-1] > S[i-1][j])
                {
                    S[i][j] += S[i][j-1];
                }
                else
                {
                    S[i][j] += S[i-1][j];
                }
            }
        }

        if (S[n][n] < 0)
        {
            cout<<"Bad Judges"<<endl;
        }
        else
        {
             printf("%.6lf\n", S[n][n]*1.0/(2*n-3));
        }
    }

    return 0;
}

