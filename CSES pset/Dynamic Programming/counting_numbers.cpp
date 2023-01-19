#include <iostream>
using namespace std;

long long calc(string n)
{
    bool bad = false;
    for (int i = 1; i < n.length(); i++)
    {
        if (bad)
        {
            n[i] = '0';
        }
        else if (n[i] == n[i - 1])
        {
            bad = true;
        }
    }

    long long mult = 1, res = 0;
    for (int i = n.length() - 1; i >= 0; i--)
    {
        res += mult * (n[i] - '0' - (i >= 1 && n[i] > n[i - 1]));
        if (i != 0)
            res += mult;
        mult *= 9;
    }
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;
    bool bad = false;
    for (int i = 1; i < b.length(); i++)
    {
        if (b[i] == b[i - 1])
        {
            bad = true;
        }
    }
    //cout << calc(a) << " " << calc(b) << endl;
    cout << calc(b) - calc(a) + !bad << endl;
}
