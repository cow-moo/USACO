#include <iostream>
#include <vector>
using namespace std;

vector<int> children[200050];
long long citizens[200050];

pair<pair<long long, long long>, int> dfs(int node)
{
    if (children[node].size() == 0)
    {
        return {{citizens[node], 0}, 1};
    }

    pair<pair<long long, long long>, int> returnInfo = {{0, 0}, 0};
    for (int child : children[node])
    {
        pair<pair<long long, long long>, int> p = dfs(child);

        if (p.first.first > returnInfo.first.first)
        {
            returnInfo.first.second += (p.first.first - returnInfo.first.first) * returnInfo.second;
            returnInfo.first.first = p.first.first;
        }
        else
        {
            p.first.second += (returnInfo.first.first - p.first.first) * p.second;
        }

        returnInfo.first.second += p.first.second;
        returnInfo.second += p.second;
    }

    returnInfo.first.second -= citizens[node];
    if (returnInfo.first.second < 0)
    {
        long long inc = (-returnInfo.first.second) / returnInfo.second + ((-returnInfo.first.second) % returnInfo.second != 0);
        returnInfo.first.second += inc * returnInfo.second;
        returnInfo.first.first += inc;
    }

    return returnInfo;
}

int main()
{
    //max, num to reach equality, num of leaves
    int n;
    cin >> n;

    for (int i = 1 ; i < n; i++)
    {
        int inp;
        cin >> inp;

        children[inp - 1].push_back(i);
    }

    for (int i = 0; i < n; i++)
        cin >> citizens[i];

    cout << dfs(0).first.first << endl;
}
