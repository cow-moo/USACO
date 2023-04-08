#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

long long coins[MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    sort(coins, coins + n);

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] > sum + 1)
        {
            break;
        }
        sum += coins[i];
    }
    cout << sum + 1 << endl;
}

//1 2 3 8
//1..6