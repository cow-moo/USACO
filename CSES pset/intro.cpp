#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > ans;

void solve(int a, int b, int n)
{
    int c = 6 - a - b;

    if (n == 1)
    {
        ans.push_back({a, b});
    }
    else
    {
        solve(a, c, n - 1);
        ans.push_back({a, b});
        solve(c, b, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    solve(1, 3, n);

    cout << ans.size() << endl;
    for (pair<int, int> p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}
