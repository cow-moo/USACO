#include <iostream>
using namespace std;
#define MAXN 200005

long long mods[MAXN];

int main()
{
    int n;
    cin >> n;

    mods[0] = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        sum = (sum + a) % n;
        if (sum < 0)
            sum += n;
        mods[sum]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += mods[i] * (mods[i] - 1) / 2;
    }
    cout << ans << endl;
}

//5 -60 -127 -194
//1 0 1 2