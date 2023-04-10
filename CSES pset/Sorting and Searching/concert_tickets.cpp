#include <iostream>
#include <set>
using namespace std;

multiset<int> tickets;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        tickets.insert(h);
    }

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        auto it = tickets.upper_bound(t);
        if (it == tickets.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *(--it) << endl;
            tickets.erase(it);
        }
    }
}