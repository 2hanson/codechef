#include <iostream>
#include <string>
using namespace std;

long long exp[27];

void init()
{
    exp[0] = 0;
    exp[1] = exp[2] = 1;
    for (int index = 3; index <= 26; ++index)
    {
        exp[index] =0;
        for (int k = 1; k < index; ++k)
        {
            exp[index] += (exp[k]*exp[index-k]);
        }
    }
}

int main()
{
    init();
    int T;
    cin>>T;
    while (T--)
    {
        string str;
        cin>>str;
        cout<<exp[str.length()]<<endl;
    }

    return 0;
}

