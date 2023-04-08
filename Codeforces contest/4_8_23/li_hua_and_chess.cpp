#include <iostream>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    cout << "? 1 1" << endl;
    cout.flush();
    int first;
    cin >> first;

    cout << "? 1 " << m << endl;
    cout.flush();
    int second;
    cin >> second;

    if (first + second == m - 1)
    {
        cout << "? 1 " << first + 1 << endl;
        cout.flush();
        int third;
        cin >> third;
        cout << "! " << third + 1 << " " << first + 1 << endl;
    }
    else
    {
        if (first < second)
            cout << "! " << first + 1 << " " << m - second << endl;
        else if (first > second)
            cout << "! " << second + 1 << " " << first + 1 << endl;
        else
        {
            cout << "? " << first + 1 << " 1" << endl;
            cout.flush();
            int third;
            cin >> third;
            cout << "! " << first + 1 << " " << third + 1 << endl;
        }
    }
    cout.flush();
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}