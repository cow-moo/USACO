#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<long long, long long> l, r;
long long arr[50];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    l[-1] = 0, r[-1] = 0;
    l[0]++, r[0]++;
    for (int i = 0; i < n; i++)
    {
        long long t = arr[i];
        //cin >> t;
        if (i < n / 2)
        {
            for (auto it = --l.end(); it != l.begin(); it--)
            {
                l[it->first + t] += it->second;
            }
        }
        else
        {
            for (auto it = --r.end(); it != r.begin(); it--)
            {
                r[it->first + t] += it->second;
            }
        }
    }
    l.erase(-1);
    r.erase(-1);
    //cout << l.size() << endl;
    auto lit = l.begin();
    auto rit = r.rbegin();
    long long ans = 0;
    while (lit != l.end() && rit != r.rend())
    {
        if (lit->first + rit->first == x)
        {
            ans += lit->second * rit->second;
            //cout << lit->first << " " << rit->first << " " << lit->second << " " << rit->second << endl;
            lit++, rit++;
        }
        else if (lit->first + rit->first < x)
        {
            lit++;
        }
        else
        {
            rit++;
        }
    }
    cout << ans << endl;
}