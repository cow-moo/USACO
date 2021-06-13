#include <iostream>
using namespace std;
#define MOD 1000000007

int arr[200050];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        int common = -1;
        //cout << common << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            common &= arr[i];
        }
        //cout << common << endl;

        long long ends = 0;
        for (int i = 0; i < n; i++)
        {
            if (common == arr[i])
                ends++;
        }
        //cout << "E" << ends << endl;

        long long ans = ends * (ends - 1);
        for (long long i = 1; i <= n - 2; i++)
        {
            ans *= i;
            ans %= MOD;
        }

        cout << ans << endl;
    }
}
