#include <iostream>
#include <string>
using namespace std;

int main() {
    string p;
    cin >> p;

    long long cur = 1, ans = 0;
    for (int i = 1; i < p.length(); i++)
    {
        if (p[i] - p[i - 1] == 1 || (p[i] == 'a' && p[i - 1] == 'z')
        {
            cur++;
        }
        else
        {
            ans += cur * ()
        }
    }
}
