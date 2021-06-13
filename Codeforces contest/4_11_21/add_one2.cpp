#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007

long long curRes[10][10];
vector<pair<pair<int, string>, int> > queries;
long long ans[200050];

void op(long long num[10])
{
    int nines = num[9];
    for (int i = 9; i >= 1; i--)
    {
        num[i] = num[i - 1];
    }
    num[0] = nines;
    num[1] += nines;
    if (num[1] >= MOD)
        num[1] -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 10; i++)
    {
        curRes[i][i] = 1;
    }


    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        string n;
        int m;
        cin >> n >> m;
        queries.push_back({{m, n}, z});
    }

    sort(queries.begin(), queries.end());

    int qIndex = 0;
    for (int i = 1; qIndex < t; i++)
    {
        for (int j = 0; j < 10; j++)
            op(curRes[j]);
        while (queries[qIndex].first.first == i)
        {
            for (int j = 0; j < queries[qIndex].first.second.size(); j++)
            {
                for (int k = 0; k < 10; k++)
                {
                    ans[queries[qIndex].second] += curRes[queries[qIndex].first.second[j] - '0'][k];
                    if (ans[queries[qIndex].second] >= MOD)
                        ans[queries[qIndex].second] -= MOD;
                }
            }
            qIndex++;
        }
    }

    for (int i = 0; i < t; i++)
    {
        cout << ans[i] << endl;
    }
}
