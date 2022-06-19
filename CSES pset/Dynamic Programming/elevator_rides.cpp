#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long weights[25];

pair<long long, long long> best[1100000];
//num complete, min in last

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 1; i < (1 << n); i++)
    {
        best[i].first = -1;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                pair<long long, long long> temp = best[i - (1 << j)];
                if (temp.second + weights[j] <= x)
                {
                    temp.second += weights[j];
                }
                else
                {
                    temp.first++;
                    temp.second = weights[j];
                }

                if (temp.first > best[i].first || (temp.first == best[i].first && temp.second < best[i].second))
                {
                    best[i] = temp;
                }
                //cout << "bruh" << endl;
            }
        }
        //cout << best[i].first << " " << best[i].second << endl;
    }

    cout << best[(1 << n) - 1].first + (bool)best[(1 << n) - 1].second << endl;
}
