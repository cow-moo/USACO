#include <iostream>
using namespace std;
#define MOD 1000000007
#define SQRT 3000

long long num450[10][10];
long long temp[10];

void op(long long num[10])
{
    int nines = num[9];
    for (int i = 9; i >= 1; i--)
    {
        num[i] = num[i - 1];
    }
    num[0] = nines;
    num[1] += nines;
    if (num[1] >= MOD)
        num[1] -= MOD;
}

void op450(long long num[10])
{
    long long res[10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            res[j] += num450[i][j] * num[i];
            res[j] %= MOD;
        }
    }

    for (int i = 0; i < 10; i++)
        num[i] = res[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    num450[0][0] = 1;
    for (int i = 0; i < SQRT; i++)
    {
        op(num450[0]);
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j < 10; j++)
            num450[i][j] = num450[0][j];
        op(num450[0]);
    }
//    for (int i = 0; i < 10; i++)
//    {
//        cout << i << ": ";
//        for (int j = 0; j < 10 ; j++)
//        {
//            cout << num450[i][j] << " ";
//        }
//        cout << endl;
//    }
        //cout << num450[0][i] << " ";

    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        string n;
        int m;
        cin >> n >> m;

        long long num[10] = {};
        for (int i = 0; i < n.size(); i++)
            num[n[i] - '0']++;

//        for (int i = 0; i < 10; i++)
//            cout << num[i] << " ";
//        cout << endl;

        for (int i = 0; i < m / SQRT; i++)
        {
            op450(num);
        }
        for (int i = 0; i < m % SQRT; i++)
        {
            op(num);
        }
        long long ans = 0;
        for (int i = 0; i < 10; i++)
        {
            ans += num[i];
            if (ans >= MOD)
                ans -= MOD;
        }
        cout << ans << endl;
    }
}
