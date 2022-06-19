#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, string> > dpPrev, dpCur;

int main()
{
    int n;
    cin >> n;

    for (int z = 0; z < n; z++)
    {
        int x;
        cin >> x;

        dpPrev.clear();
        dpCur.clear();
        dpPrev.resize(x + 2, {0, ""});
        dpCur.resize(x + 2, {0, ""});

        for (int i = 1; i <= x + 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long cur;
                cin >> cur;

                if (j == 0)
                {
                    dpCur[0].first = dpPrev[0].first + cur;
                    dpCur[0].second = dpPrev[0].second + "L";
                }
                else
                {
                    //goes L if its a tie
                    if (dpPrev[j].first > dpPrev[j - 1].first)
                    {
                        dpCur[j].first = dpPrev[j].first + cur;
                        dpCur[j].second = dpPrev[j].second + "L";
                    }
                    else
                    {
                        dpCur[j].first = dpPrev[j - 1].first + cur;
                        dpCur[j].second = dpPrev[j - 1].second + "R";
                    }

                    //cout << i << " " << j << " " << dpCur[j].first << dpCur[j].second << endl;
                    //dpCur[j].first == max(dpPrev[j].first, dpPrev[j - 1].first) + cur;
                    //dpCur[j].second = dpPrev[j].fir
                }
            }
            dpPrev = dpCur;
        }

        long long ansi = 0;
        for (int i = 0; i < x + 1; i++)
        {
            //ans = max(ans, dpPrev[i]);
            if (dpPrev[i].first > dpPrev[ansi].first)
                ansi = i;
        }
        cout << dpPrev[ansi].second.substr(1, -1) << " = " << dpPrev[ansi].first << endl;
    }
}
/*
3
4
4
3 6
9 1 2
5 8 10 7
10 8 6 8 10
4
4
3 0
9 0 0
5 0 0 0
10 0 0 0 0
4
4
4 4
4 4 4
4 4 4 4
4 4 4 4 4

*/
