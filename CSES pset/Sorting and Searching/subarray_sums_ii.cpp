#include <iostream>
#include <map>
using namespace std;

map<long long, int> cnt;

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    cnt[0] = 1;
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        sum += a;
        if (cnt.count(sum - x))
        {
            ans += cnt[sum - x];
        }
        cnt[sum]++;
    }
    // for (auto p : cnt)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
    cout << ans << endl;
}