#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum = 0;
    long long maxim = 0;
    for (int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        sum += t;
        maxim = max(maxim, t);
    }
    cout << max(2 * maxim, sum) << endl;
}