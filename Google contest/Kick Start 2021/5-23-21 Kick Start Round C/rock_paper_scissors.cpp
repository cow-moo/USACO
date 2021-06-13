#include <iostream>
using namespace std;

int main()
{
    int t, x;
    cin >> t >> x;

    for (int z = 1; z <= t; z++)
    {
        int w, e;
        cin >> w >> e;
        cout << "Case #" << z << ": R";
        float eVal = (float)(w + e) / 3;
        int rps[3] = {1, 0, 0};
        string str = "RPS";
        for (int i = 1; i < 60; i++)
        {
            int maxim = 0;
            int maxChoice;
            for (int j = 0; j < 3; j++)
            {
                if (rps[j] * e + rps[(j + 2) % 3] * w > maxim)
                {
                    maxim = rps[j] * e + rps[(j + 2) % 3] * w;
                    maxChoice = j;
                }
            }
            eVal += (float)maxim / i;
            rps[maxChoice]++;
            cout << str[maxChoice];
        }
        cout << endl;
        cout << eVal << endl;
    }
}
