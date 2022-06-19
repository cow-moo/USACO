#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 100050

//pos, dir, label
pair<pair<long long, bool>, int> ant[MAXN];
//time, side
pair<long long, bool> times[MAXN];

set<int> sameTime;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long n, l;
        cin >> n >> l;

        for (int i = 0; i < n; i++)
        {
            cin >> ant[i].first.first >> ant[i].first.second;
            ant[i].second = i + 1;
        }
        sort(ant, ant + n);

        for (int i = 0; i < n; i++)
        {
            times[i].second = ant[i].first.second;
            if (ant[i].first.second == 0)
            {
                times[i].first = ant[i].first.first;
            }
            else
            {
                times[i].first = l - ant[i].first.first;
            }
        }
        sort(times, times + n);
        times[n] = {-1, -1};

//        for (int i = 0; i < n; i++)
//        {
//            cout << times[i].first << ":" << times[i].second << " ";
//        }
//        cout << endl;

        int le = 0, r = n - 1;

        cout << "Case #" << z << ": ";
        for (int i = 0 ; i < n; i++)
        {
            if (times[i].second == 0)
            {
                sameTime.insert(ant[le++].second);
                //cout << ant[le++].second << " ";
            }
            else
            {
                sameTime.insert(ant[r--].second);
                //cout << ant[r--].second << " ";
            }

            if (times[i].first != times[i + 1].first)
            {
                //cout << sameTime.size() << endl;
                for (int label : sameTime)
                    cout << label << " ";
                sameTime.clear();
            }
        }
        cout << endl;
    }
}
