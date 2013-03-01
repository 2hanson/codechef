#include <iostream>
#include <string>
using namespace std;

string alps;

bool is_low_alp(char ch)
{
    return (ch>='a' && ch<='z');
}

bool is_up_alp(char ch)
{
    return (ch>='A' && ch<='Z');
}

int main()
{
    int T;
    cin>>T;
    cin>>alps;
    string conv;
    while (T--)
    {
        cin>>conv;
        for (int k = 0; k < conv.length(); ++k)
        {
            char ch = conv[k];
            if (is_low_alp( ch ))
            {
                ch = alps[ ch-'a' ];
            }
            else if (is_up_alp( ch ))
            {
                ch = alps[ ch - 'A' ] - 'a' + 'A';
            }
            else if (ch == '_')
            {
                ch = ' ';
            }

            cout<<ch;
        }

        cout<<endl;
    }

    return 0;
}

