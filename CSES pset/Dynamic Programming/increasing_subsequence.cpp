#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200050
#define INF 1000000000

int smallest[MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        smallest[i] = INF;

    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;

        int index = lower_bound(smallest, smallest + n, inp) - smallest;
        smallest[index] = min(smallest[index], inp);
    }

    for (int i = n; i >= 1; i--)
    {
        if (smallest[i] != INF)
        {
            cout << i << endl;
            break;
        }
    }
}
