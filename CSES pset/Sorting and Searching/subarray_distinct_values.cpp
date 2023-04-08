#include <iostream>
#include <map>
using namespace std;
#define MAXN 200005

int active[MAXN];
map<int, int> recent;

int main()
{
    int n, k;
    cin >> n >> k;

    long long ans = 0;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> active[i];

        if (recent.count(active[i]) == 0 || recent[active[i]] < l)
        {
            k--;
        }
        if (recent.count(active[i]) > 0)
        {
            active[recent[active[i]]] = 0;
        }
        recent[active[i]] = i;

        if (k < 0)
        {
            while (l < i && active[l] == 0)
                l++;
            l++;
            k++;
        }
        ans += i - l + 1;
    }

    cout << ans << endl;
}