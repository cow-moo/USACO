#include <iostream>
using namespace std;
#define MAXN 100010

long long arr[MAXN];

long long solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr[n++] = 0;
    arr[n++] = 0;
    arr[n] = 0;
    arr[n + 1] = 0;

    long long prev[] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        arr[i] -= prev[i % 2];
        prev[i % 2] += arr[i];
    }

    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    long long doubles = 0, singles[2] = {0, 0};

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        //cout << arr[i] << " ";
        if (arr[i] > 0)
        {
            if (i + 1 < n && arr[i + 1] > 0)
            {
                if (arr[i] < arr[i + 1])
                {
                    doubles += arr[i];
                    arr[i + 1] -= arr[i];
                    arr[i] = 0;
                }
                else
                {
                    doubles += arr[i + 1];
                    singles[i % 2] += arr[i] - arr[i + 1];
                    arr[i + 1] = 0;
                    arr[i] = 0;
                }
            }
            else
            {
                singles[i % 2] += arr[i];
                arr[i] = 0;
            }
        }
        else if (arr[i] < 0)
        {
            long long amt = min(doubles, -arr[i]);
            //if <= 0 then 0
            //if (i + 2 < n && arr[i + 2] > 0)
            //{
                amt = min(amt, max(0ll, (arr[i + 2] <= 0 ? 0 : arr[i + 2]) - arr[i + 1]));
            //}
            doubles -= amt;
            ans += amt;
            arr[i] += amt;
            if (i + 1 < n)
            {
                arr[i + 1] += amt;
            }
            if (arr[i] < 0)
            {
                singles[i % 2] += arr[i];
                ans -= arr[i];
                arr[i] = 0;

                if (singles[i % 2] < 0)
                {
                    long long amt = -singles[i % 2];
                    doubles -= amt;
                    singles[0] += amt;
                    singles[1] += amt;
                }
            }
        }

        //cout << i << ": " << ans << " " << doubles << " " << singles[0] << " " << singles[1] << endl;
    }

    return ans + doubles + singles[0] + singles[1];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }
}
/*
3
5
2 1 2 1 2
8
1000000000 1000000000 0 1000000000 1000000000 0 1000000000 1000000000
13
1 1 4 5 1 4 1 9 1 9 8 1 0

8
1 1 0 1 1 0 1 1

5
100 3 3 10 11

97 0 0 7 8: 3
0 0 0 7 8: 100

1 9 8 7 3 90 2 3 2 0
0 8 7 6 2 89 1 2 1 0 : 1
0 8 6 6 1 89 0 2 0 0 : 1
0 6 6 4 1 87 0 0 0 0 : 2
0 5 5 3 0 86 0 0 0 0 : 1
0 0 0 0 0 0 0 0 0 0 : 91

10
1 9 8 7 3 90 2 3 2 0

9
1 9 8 7 3 90 2 3 2
*/