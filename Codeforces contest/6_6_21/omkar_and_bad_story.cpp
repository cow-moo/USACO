#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        vector<int> b;
        set<int> bset;
        for (int i = 0; i < n; i++)
        {
            int inp;
            cin >> inp;
            b.push_back(inp);
            bset.insert(inp);
        }

        for (int i = 1; i < b.size(); i++)
        {
            if (b.size() > 300)
                break;
            for (int j = 0; j < i; j++)
            {
                if (bset.count(abs(b[i] - b[j])) == 0)
                {
                    bset.insert(abs(b[i] - b[j]));
                    b.push_back(abs(b[i] - b[j]));
                }
            }
        }

        if (b.size() > 300)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        cout << b.size() << endl;
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}
