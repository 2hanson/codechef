#include <iostream>
#include <vector>
using namespace std;

const int maxn = 20;
int N, K, M;
int R[maxn];
int ans;
void solve_dfs(int pos, int tans);

void getMaxIndex(int left, int right, vector<int> &vec)
{
    int max = R[left];
    for (int i = left; i <= right; ++i)
    {
        if (R[i] > max)
        {
            max = R[i];
        }
    }

    for (int i = left; i <= right; ++i)
    {
        if (R[i] == max)
        {
            vec.push_back(i);
        }
    }
}

bool destroy_pre(int cur)
{
    for (int pos = 1; pos < cur; ++pos)
    {
        vector<int> max_vec;
        getMaxIndex(pos, pos+K-1, max_vec);
        if (max_vec.size() >= M)
            return true;
    }

    return false;
}

void inc_dfs(int index, int num, int pos, int tans, vector<int> &vec)
{
    if (ans != -1 && tans > ans)
    {
        return;
    }
    if (num < M)
    {
        solve_dfs(pos, tans);
    }
    if (index >= vec.size())
        return;
    ++R[vec[index]];
    if (destroy_pre(pos) == true)
    {
        --R[vec[index]];
        return;
    }
    cout<<"pos: "<<pos-1<<" index:"<<index<<endl;
    for (int i = index + 1; i < vec.size(); ++i)
    {
        inc_dfs(i, num-1, pos, tans+1, vec);
    }
    --R[vec[index]];
}

void solve_dfs(int pos, int tans)
{
    if (ans != -1 && tans > ans)
    {
        return;
    }
    //pos, ..., pos+k-1
    if (pos + K - 1 > N)
    {
        if (ans == -1 || ans > tans)
        {
            cout<<"solve: "<<tans<<endl;
            for (int i = 1; i <= N; ++i)
            {
                cout<<R[i]<<endl;
            }
            ans = tans;
        }
        return;
    }
    vector<int> max_vec;
    getMaxIndex(pos, pos+K-1, max_vec);
    
    for (int index = 0; index < max_vec.size(); ++index)
    {
     //   cout<<"pos: "<<pos<<" : "<<index<<" : "<<max_vec[index]<<endl;
        inc_dfs(index, max_vec.size(), pos+1, tans, max_vec);
        //++R[ max_vec[index] ];
        //solve_dfs(pos+1, tans);
        //--R[ max_vec[index] ];
    }
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>N>>K>>M;    
        ans = -1;//max = 17
        for (int i = 1; i <= N; ++i)
        {
            cin>>R[i];
        }

        if (M == 1)
        {
            cout<<-1<<endl;
            continue;
        }
        solve_dfs(1, 0);
    
        cout<<ans<<endl;
    }

    return 0;
}

