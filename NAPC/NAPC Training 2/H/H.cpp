#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
#define T __int128_t

int d, h;
T fact[32];

vector<unsigned long long> ans;

void dfs(T tot, T index, T cur, T sum)
{
    if (index == d - 1)
    {
        ans.push_back(tot / fact[h - 1 - sum]);
        return;
    }
    for (T i = cur; ; i++)
    {
        if (i * (d - index) + sum > h - 1)
            break;
        dfs(tot / fact[i], index + 1, i, sum + i);
    }
}

int main()
{
    fact[0] = 1;
    for (T i = 1; i < 32; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    cin >> d >> h;

    dfs(fact[h - 1], 0, 0, 0);

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for (auto x : ans)
        cout << (unsigned long long)x << endl;
}