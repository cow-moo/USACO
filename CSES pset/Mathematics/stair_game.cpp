#include <iostream>
using namespace std;

string solve()
{
    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        
        if (i % 2 == 1)
            res ^= p;
    }
    return res != 0 ? "first" : "second";
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
        cout << solve() << endl;
}