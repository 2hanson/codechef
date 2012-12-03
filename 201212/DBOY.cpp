#include <iostream>
using namespace std;

const int maxn = 505;
int H[maxn];
int K[maxn];
int d = 0;
int ans[2*maxn];

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int N;
        cin>>N;
        d = 0;
        for (int i = 1; i <= N; ++i)
        {
            cin>>H[i];
            if (2*H[i] > d)
            {
                d = 2*H[i];
            }
        }

        for (int i = 1; i <= d; ++i)
        {
            ans[i] = -1;            
        }

        for (int i = 1; i <= N; ++i)
        {
            cin>>K[i];
            ans[ K[i] ] = 1;
        }
       
        bool flag = false;
        for (int count = 1; count <= d && flag == false; ++count)
        {
            flag = true;
            for (int a = 1; a <= d; ++a)
            {
                for (int b = 1; b <= d; ++b)
                {
                    if (ans[a] != -1 && ans[b] != -1)
                    {
                        if (a+b <= d)
                        {
                            if (ans[a+b] == -1)
                            {
                                flag = false;
                                ans[a+b] = ans[a] + ans[b];
                            }
                            else if (ans[a+b] > ans[a] + ans[b])
                            {
                                flag = false;
                                ans[a+b] = ans[a] + ans[b];
                            }
                        }
                    }
                }
            }
        }

        int num = 0;

        for (int i = 1; i <= N; ++i)
        {
            num += ans[ 2*H[i] ];
        }

        cout<<num<<endl;
    }

    return 0;
}

