#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

long long arr[MAXN];
long long prefix[MAXN], suffix[MAXN];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    suffix[n] = arr[n - 1] + 10000;
    for (int i = n - 1; i >= 0; i--)
    {
        suffix[i] = min(arr[i], suffix[i + 1]);
    }

    arr[0] += n;
    long long minim = arr[0], sum = arr[0];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i] += n - i;
        sum += arr[i];
        if (i != n - 1 && (minim == -1 || minim > arr[i]))
            minim = arr[i];
        prefix[i] = min(arr[i], prefix[i - 1]);
    }

    for (int i = 0; i < q; i++)
    {
        long long k;
        cin >> k;

        if (k <= n)
        {
            cout << min(suffix[k], prefix[k - 1] - (n - k)) << " ";
            continue;
        }

        long long asdf = sum, asdf2 = minim;
        if ((k - n) % 2 == 1)
        {
            asdf -= k - n + 1;
            asdf2 = min(minim, arr[n - 1] - k + n - 1);
        }
        else
            asdf2 = min(minim, arr[n - 1]);
        
        long long diff = asdf - asdf2 * n;
        long long ops = (k - n + 1) / 2 - diff;
        long long ans = asdf2 - (ops > 0 ? (ops + n - 1) / n : 0);
        cout << ans + k - n << " ";
    }
}