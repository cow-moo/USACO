#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

//long long weights[200050];
multiset<long long> weights;
bool used[200050];

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        long long inp;
        cin >> inp;
        weights.insert(inp);
       //cin >> weights[i];
    }

    //sort(weights, weights + n);

    for (auto rit = weights.rbegin(); rit != weights.rend(); ++rit)
    {
        auto it = weights.upper_bound(x - *rit);
        if (it == weights.end())
        {
            it--; it--;
        }
        else if (it != weights.begin())
        {
            it--;
        }
        else
        {
            continue;
        }

        weights.erase(rit);
        weights.erase(it);
    }

    cout << weights.size() << endl;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        int pos = --upper_bound(weights, weights + n, x - weights[i]);
//        if (pos != -1)
//        {
//
//        }
//    }
}
