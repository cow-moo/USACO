#include <iostream>
using namespace std;

int query(int n, int k)
{
    //n = 2m
    //1, 3, ..., 2m - 1

    //n = 2m+1
    //1, 3, ..., 2m + 1
    if (n == 1)
        return 1;
    if (k <= n / 2)
    {
        return k * 2;
    }
    else
    {
        int res = query(n - n / 2, k - n / 2);
        if (n % 2 == 1)
        {
            if (res == 1)
                return n;
            res--;
        }
        return 2 * res - 1;
    }
}

int main()
{
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int n, k;
        cin >> n >> k;
        cout << query(n, k) << endl;;
    }
}