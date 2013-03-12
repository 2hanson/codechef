#include <iostream>
#include <vector>
using namespace std;

vector<int> steps;

int main()
{
    int T;
    long long X;
    cin>>T;
    while (T--)
    {
        cin>>X;
        if ((X&1) == 0)
        {
            cout<<"0"<<endl;
        }
        else if (X == 1)
        {
            cout<<""<<endl;
        }
        else
        {
            steps.clear();
            while(X > 1)
            {
                //even
                if ( (((X+1)>>1)&1) != 0)
                {
                    X = (X+1)>>1;
                    steps.push_back(1);
                }
                //odd
                else
                {
                    X = (X-1)>>1;
                    steps.push_back(2);
                }
            }
            for (int i = steps.size()-1; i >= 0; --i)
            {
                cout<<steps[i];
            }
            cout<<endl;
        }
    }

    return 0;
}

