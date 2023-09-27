#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;

        int pow = 0;
        bool same = true;
        long long s;
        cin >> s;
        while (!(s >> pow & 1))
            pow++;
        
        for (int i = 1; i < n; i++)
        {
            long long s;
            cin >> s;
            int p = 0;
            while (!(s >> p & 1))
                p++;
            if (p != pow) same = false;
        }
        if (n & 1)
        {
            cout << !same << endl;
        }
        else
        {
            cout << !(same && pow == 0) << endl;
        }
    }
}