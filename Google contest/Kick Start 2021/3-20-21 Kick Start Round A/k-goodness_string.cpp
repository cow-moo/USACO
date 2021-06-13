#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int goodness = 0;
        for (int i = 0; i < n / 2; i++)
        {
            //cout << s[i] << ", " << s[n - i - 1] << endl;
            if (s[i] != s[n - i - 1])
                goodness++;
        }
        //cout << "g" << goodness << endl;

        cout << "Case #" << z << ": " << abs(k - goodness) << endl;
    }
}
