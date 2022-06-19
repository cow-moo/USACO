#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 200050

multiset<long long> applicants;
long long apartments[MAXN];

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        applicants.insert(inp);
    }

    for (int i = 0; i < m; i++)
        cin >> apartments[i];

    sort(apartments, apartments + m);

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        long long inp = apartments[i];
        //cin >> inp;

        auto it = applicants.lower_bound(inp - k);
        if (it != applicants.end() && *it <= inp + k)
        {
            applicants.erase(it);
            ans++;
        }
    }

    cout << ans << endl;
}
