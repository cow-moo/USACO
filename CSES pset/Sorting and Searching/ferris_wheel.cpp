#include <iostream>
#include <set>
using namespace std;

multiset<int> weights;

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        weights.insert(p);
    }

    int ans = n;
    for (auto it = weights.begin(); it != weights.end(); it++)
    {
        auto other = weights.upper_bound(x - *it);
        if (other == weights.begin())
            break;
        other--;
        if (*other < *it || other == it)
            break;

        ans--;
        weights.erase(other);
    }
    cout << ans << endl;
}