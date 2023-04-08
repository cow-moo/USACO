#include <iostream>
using namespace std;
#define MAXN 200005

bool found[MAXN];

int main()
{
    int n;
    cin >> n;

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (found[x + 1])
            ans++;
        found[x] = true;
    }
    cout << ans << endl;
}