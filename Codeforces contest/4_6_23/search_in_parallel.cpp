#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200005

pair<int, int> colors[MAXN];
vector<int> a, b;

void solve()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;

    for (int i = 0; i < n; i++)
    {
        cin >> colors[i].first;
        colors[i].first *= -1;
        colors[i].second = i + 1;
    }
    a.clear(), b.clear();

    sort(colors, colors + n);

    int t1 = s1, t2 = s2;

    for (int i = 0; i < n; i++)
    {
        if (t1 < t2)
        {
            a.push_back(colors[i].second);
            t1 += s1;
        }
        else
        {
            b.push_back(colors[i].second);
            t2 += s2;
        }
    }
    cout << a.size() << " ";
    for (int x : a)
        cout << x << " ";
    cout << endl << b.size() << " ";
    for (int x : b)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}