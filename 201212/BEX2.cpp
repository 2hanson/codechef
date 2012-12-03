#include <iostream>
#include <string.h>

using namespace std;

const long maxn = 10000005;
char books[maxn][18];
long ans[maxn];
long E[maxn];

int main()
{
    long N;
    //cin>>N;
    scanf("%ld", &N);
    long num = 0;
    long curE = -1;
    long tempE;
    char bookName[18];

    for (int index = 0; index < N; ++index)
    {
        //cin>>tempE;
        scanf("%ld", &tempE);   
        if (-1 == tempE)
        {
            printf("%ld %s\n", ans[num-1], books[num-1]);
            //cout<<ans[num-1]<<" "<<books[num-1]<<endl;
            --num;
            if (num <= 0)
            {
                num = 0;
                curE = -1;
            }
            else
            {
                curE = E[num-1];
            }
        }
        else
        {
            //cin>>bookName;
            scanf("%s", bookName);
            if (tempE > 0){
                if (curE == -1)
                {
                    curE = tempE;
                    ans[num] = 0;
                    E[num] = tempE;
                    strcpy(books[num], bookName);
                   // books[num] = bookName;
                    ++num;
                }
                else if (tempE > curE)
                {
                    ++ans[ num-1 ];
                }
                else
                {    
                    curE = tempE;
                    ans[num] = 0;
                    E[num] = tempE;
                    strcpy(books[num], bookName);
                    //books[num] = bookName;
                    ++num;
                }
            }
        }

    }

    return 0;
}
