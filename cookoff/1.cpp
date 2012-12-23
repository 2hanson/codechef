#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

const int maxn = 45;
char ins[maxn][55];
int dir[maxn];
int n;

void getLine(int index)
{
    bool flag = 0;
    int c, i;
    c = getchar();
    if (index > 0)
    {
        if (c == 'R')
        {
            dir[index-1] = 1;//left
            int temp = 9; 
            while (temp--)
            {
                c = getchar();
            }
        }
        else
        {
            dir[index-1] = 2;//right
            int temp = 8; 
            while (temp--)
            {
                c = getchar();
            }
        }
    }
    else
    {
        int temp = 9; 
        while (temp--)
        {
            c = getchar();
        }
    }

    ins[index][0] = c;
    for (i = 1; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        ins[index][i] = c;
    }

    ins[index][i] = '\0';
}

void out()
{
    
    printf("Begin on %s\n", ins[n-1]);
    for (int i = n-2; i >= 0; --i)
    {
        if (dir[i] == 1)
        {
            printf("Left on %s\n", ins[i]);
        }
        else
        {
            printf("Right on %s\n", ins[i]);
        }
    }
}

int main()
{
    int t;
  
    cin>>t;
    while (t--)
    {
        cin>>n;
        getchar();//for \n
        for (int i = 0; i < n; ++i)
        {
            getLine(i);
        }
        out();
        cout<<endl;
    }
    return 0;
}

