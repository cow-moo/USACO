#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
#define MAXN 5005

long long arr[MAXN], prefix[MAXN], dp[MAXN][MAXN];
int n;

long long slow()
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j + i <= n; j++)
        {
            dp[i][j] = dp[i - 1][j + 1];
            for (int k = 2; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j + k]);
            }
            dp[i][j] += prefix[i + j] - prefix[j];
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    return dp[n][0];
}

long long recurse(int l, int r)
{
    if (l + 1 == r)
        return 0;
    int m = l + 1;
    for (int i = l + 1; i < r; i++)
    {
        if (min(prefix[i] - prefix[l], prefix[r] - prefix[i]) > min(prefix[m] - prefix[l], prefix[r] - prefix[m]))
            m = i;
    }
    //cout << l << " " << m << " " << r << " " << prefix[r] - prefix[l] << endl;
    long long best = recurse(l, m) + recurse(m, r) + prefix[r] - prefix[l];
    if (m + 1 < r)
        best = min(best, recurse(l, m + 1) + recurse(m + 1, r) + prefix[r] - prefix[l]);
    if (m > l + 1)
        best = min(best, recurse(l, m - 1) + recurse(m - 1, r) + prefix[r] - prefix[l]);
    return best;
}

void test()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;

    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = uniform_int_distribution<int>(0, 100)(rng);
            //cin >> arr[i];
            prefix[i + 1] = prefix[i] + arr[i];
        }

        long long a = slow(), b = recurse(0, n);
        cout << a << " " << b << endl;
        if (a != b)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }

    //cout << slow() << endl;
    //cout << recurse(0, n) << endl;
}

//80 55 7 67 50
//11 8 1 10 7

//37
//11 8
//1 10 7

//19
//11
//8

//18
//1 10
//7

//11
//1
//10

//11 8 1 10 7

//37
//11 8 1
//10 7

//20
//11
//8 1

//17
//10
//7

//9
//8
//1