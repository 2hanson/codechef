#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> name_country;
map<string, long> name_vote;
map<string , long> country_vote;
long N,M;

int main()
{
    string tcn;
    string tcc;
    cin>>N>>M;
    while (N--)
    {
        cin>>tcn>>tcc;
        name_country[tcn] = tcc;
        name_vote[tcn] = 0;
        country_vote[tcc] = 0;
    }
   
    string ans = tcn;
    string ans_country = tcc;
    long ans_country_vote = 0;
    long ans_name_vote = 0;
    while (M--)
    {
        cin>>tcn;
        long temp_name_vote = name_vote[tcn] = name_vote[tcn]+1;
        tcc = name_country[tcn];
        long temp_country_vote = country_vote[tcc] = country_vote[tcc]+1;
        
        ans_country_vote = country_vote[ans_country];
        if (temp_country_vote > ans_country_vote)
        {
            ans_country = tcc;
        }
        else if (temp_country_vote == ans_country_vote && tcc < ans_country)
        {
            ans_country = tcc;
        }
            
        ans_name_vote = name_vote[ans];
        if (temp_name_vote > ans_name_vote)
        {
            ans = tcn;
        }
        else if (ans_name_vote == temp_name_vote && tcn < ans)
        {
            ans = tcn;
        }
    }

    cout<<ans_country<<endl<<ans<<endl;
    return 0;
}

