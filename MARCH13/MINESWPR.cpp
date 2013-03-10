#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int maxn = 100;
int n, m, k;
int map[maxn][maxn];

int walkx[4] = {0, 1, 1, 1};
int walky[4] = {1, -1, 0, 1};

char Survey(int x, int y) {
    printf("S %d %d\n", x, y);
    fflush(stdout);
    char res;
    scanf(" %c", &res);
    return res;
}

void Neutralize(int x, int y) {
    printf("N %d %d\n", x, y);
    fflush(stdout); /* but it is not necessary here */
}

void Done() {
    printf("Done\n");
    fflush(stdout); /* but it is not necessary here */
}
void init()
{
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            map[i][k] = 1;
        }
    }
}

bool isvalid(int x, int y)
{
    return (x>=0 && x<n && y>=0 && y<n);
}

void solve()
{
    char suv;
    
    for (int row = 0; row<n; ++row)
    {
        for (int col = 0; col<n; ++col)
        {
            if (map[row][col] == 0)
                continue;
            suv = Survey(row, col);
            if (suv == 'M')
            {
                Neutralize(row, col);
                --m;
                if (m == 0)
                {
                    return;
                }
                suv = Survey(row, col);
            }

            int mines = suv - '0';
            if (mines == 0)
            {
                int tx, ty;
                for (int i = 0; i < 4; ++i)
                {
                    tx = row + walkx[i];
                    ty = col + walky[i];
                    if (isvalid(tx, ty) == false)
                        continue;
                    map[tx][ty] = 0;
                }
            }
        }
    }
}

int main()
{
    init();
    solve();
    Done();
    return 0;
}

